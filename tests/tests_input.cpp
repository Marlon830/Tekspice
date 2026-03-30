/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_input.cpp
*/

#include "criterion/criterion.h"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "Simulation.hpp"

Test(input_component, first_value_test) {
    nts::InputComponent inputComponent("INPUT");

    cr_assert_eq(inputComponent.compute(1), nts::Tristate::Undefined);
}

Test(input_component, compute_test_1) {
    nts::InputComponent inputComponent("INPUT");

    inputComponent.setNextValue(nts::Tristate::True);
    inputComponent.simulate(1);
    cr_assert_eq(inputComponent.compute(1), nts::Tristate::True);
}

Test(input_component, compute_test_2) {
    nts::InputComponent inputComponent("INPUT");

    inputComponent.setNextValue(nts::Tristate::False);
    inputComponent.simulate(1);
    cr_assert_eq(inputComponent.compute(1), nts::Tristate::False);
}

Test(input_component, compute_test_3) {
    nts::InputComponent inputComponent("INPUT");

    inputComponent.setNextValue(nts::Tristate::Undefined);
    inputComponent.simulate(1);
    cr_assert_eq(inputComponent.compute(1), nts::Tristate::Undefined);
}

Test(input_component, compute_test_4) {
    nts::InputComponent inputComponent("INPUT");

    inputComponent.setNextValue(nts::Tristate::True);
    inputComponent.simulate(1);
    inputComponent.setNextValue(nts::Tristate::False);
    inputComponent.simulate(1);
    inputComponent.simulate(1);
    inputComponent.simulate(1);
    inputComponent.simulate(1);
    cr_assert_eq(inputComponent.compute(1), nts::Tristate::False);
}

Test(input_component, compute_test_5_link_input) {
    nts::InputComponent inputComponent("INPUT");
    nts::InputComponent inputComponent2("INPUT");

    inputComponent.setNextValue(nts::Tristate::True);
    inputComponent.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::False);
    inputComponent2.simulate(1);
    inputComponent2.setLink(1, inputComponent, 1);
    cr_assert_eq(inputComponent2.compute(1), nts::Tristate::True);
}

Test(input_component, compute_test_6_link_output) {
    nts::InputComponent inputComponent("INPUT");
    nts::InputComponent inputComponent2("INPUT");
    nts::OutputComponent outputComponent("INPUT");

    outputComponent.setNextValue(nts::Tristate::False);
    outputComponent.simulate(1);

    inputComponent.setNextValue(nts::Tristate::True);
    inputComponent.simulate(1);

    inputComponent2.setNextValue(nts::Tristate::False);
    inputComponent2.simulate(1);

    outputComponent.setLink(1, inputComponent, 1);
    inputComponent2.setLink(1, outputComponent, 1);
    inputComponent2.switchLinkedToCircuit();
    nts::Simulation::maxActualTick += 1;
    cr_assert_eq(inputComponent2.compute(1), nts::Tristate::True);
}
