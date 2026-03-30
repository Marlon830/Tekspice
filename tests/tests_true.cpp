/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_true.cpp
*/

#include <criterion/criterion.h>
#include "TrueComponent.hpp"

Test(true_component, first_value_test) {
    nts::TrueComponent trueComponent("TRUE");

    cr_assert_eq(trueComponent.compute(1), nts::Tristate::True);
}

Test(true_component, compute_test_1) {
    nts::TrueComponent trueComponent("TRUE");

    trueComponent.simulate(1);
    cr_assert_eq(trueComponent.compute(1), nts::Tristate::True);
}
