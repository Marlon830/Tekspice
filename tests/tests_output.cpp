/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_output.cpp
*/

#include <criterion/criterion.h>
#include "OutputComponent.hpp"
#include "InputComponent.hpp"
#include "ClockComponent.hpp"
#include "Simulation.hpp"

Test(output_component, first_value_test) {
    nts::OutputComponent outputComponent("OUTPUT");

    cr_assert_eq(outputComponent.compute(1), nts::Tristate::Undefined);
}

Test(output_component, compute_test_1) {
    nts::OutputComponent outputComponent("OUTPUT");
    nts::InputComponent inputComponent("INPUT");

    inputComponent.setNextValue(nts::Tristate::True);
    inputComponent.simulate(1);
    outputComponent.setLink(1, inputComponent, 1);
    nts::Simulation::maxActualTick += 1;
    cr_assert_eq(outputComponent.compute(1), nts::Tristate::True);
}

Test(output_component, compute_test_2) {
    nts::OutputComponent outputComponent("OUTPUT");
    nts::InputComponent inputComponent("INPUT");

    inputComponent.setNextValue(nts::Tristate::False);
    inputComponent.simulate(1);
    outputComponent.setLink(1, inputComponent, 1);
    nts::Simulation::maxActualTick += 1;
    cr_assert_eq(outputComponent.compute(1), nts::Tristate::False);
}

Test(output_component, compute_test_3) {
    nts::OutputComponent outputComponent("OUTPUT");
    nts::ClockComponent clockComponent("CLOCK");

    clockComponent.setNextValue(nts::Tristate::True);
    clockComponent.simulate(1);
    outputComponent.setLink(1, clockComponent, 1);
    nts::Simulation::maxActualTick += 1;
    cr_assert_eq(outputComponent.compute(1), nts::Tristate::True);
}

Test(output_component, compute_test_4) {
    nts::OutputComponent outputComponent("OUTPUT");
    nts::ClockComponent clockComponent("CLOCK");

    clockComponent.setNextValue(nts::Tristate::True);
    clockComponent.simulate(1);
    clockComponent.simulate(1);
    outputComponent.setLink(1, clockComponent, 1);
    nts::Simulation::maxActualTick += 1;
    cr_assert_eq(outputComponent.compute(1), nts::Tristate::False);
}

Test(output_component, compute_test_5_does_not_compute) {
    nts::InputComponent inputComponent("INPUT");
    nts::OutputComponent outputComponent("OUTPUT");
    nts::OutputComponent outputComponent2("OUTPUT");

    inputComponent.setNextValue(nts::Tristate::True);
    inputComponent.simulate(1);
    outputComponent2.setLink(1, inputComponent, 1);
    outputComponent.setLink(1, outputComponent2, 1);
    cr_assert_eq(outputComponent.compute(1), nts::Tristate::Undefined);
    nts::Simulation::maxActualTick += 1;
    cr_assert_eq(outputComponent.compute(1), nts::Tristate::True);
}

Test(output_component, compute_test_6_no_links_at_all_but_try_to_compute) {
    nts::OutputComponent outputComponent("OUTPUT");

    nts::Simulation::maxActualTick += 1;
    cr_assert_eq(outputComponent.compute(1), nts::Tristate::Undefined);
}
