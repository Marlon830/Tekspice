/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_and.cpp
*/

#include <criterion/criterion.h>
#include "ClockComponent.hpp"

Test(clock_component, first_value_test) {
    nts::ClockComponent clockComponent("CLOCK");

    cr_assert_eq(clockComponent.compute(1), nts::Tristate::Undefined);
}

Test(clock_component, compute_test_1) {
    nts::ClockComponent clockComponent("CLOCK");

    clockComponent.setNextValue(nts::Tristate::True);
    clockComponent.simulate(1);
    cr_assert_eq(clockComponent.compute(1), nts::Tristate::True);
}

Test(clock_component, compute_test_2) {
    nts::ClockComponent clockComponent("CLOCK");

    clockComponent.setNextValue(nts::Tristate::True);
    clockComponent.simulate(1);
    clockComponent.simulate(1);
    cr_assert_eq(clockComponent.compute(1), nts::Tristate::False);
}

Test(clock_component, compute_test_3) {
    nts::ClockComponent clockComponent("CLOCK");
    nts::ClockComponent clockComponent2("CLOCK");

    clockComponent2.setNextValue(nts::Tristate::False);
    clockComponent2.simulate(1);
    clockComponent2.setLink(1, clockComponent, 1);
    clockComponent.setNextValue(nts::Tristate::True);
    clockComponent.simulate(1);
    cr_assert_eq(clockComponent2.compute(1), nts::Tristate::True);
}
