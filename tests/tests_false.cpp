/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_false.cpp
*/

#include <criterion/criterion.h>
#include "FalseComponent.hpp"

Test(false_component, first_value_test) {
    nts::FalseComponent falseComponent("FALSE");

    cr_assert_eq(falseComponent.compute(1), nts::Tristate::False);
}

Test(false_component, compute_test_1) {
    nts::FalseComponent falseComponent("FALSE");

    falseComponent.simulate(1);
    cr_assert_eq(falseComponent.compute(1), nts::Tristate::False);
}
