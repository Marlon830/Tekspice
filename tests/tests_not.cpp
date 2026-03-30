/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_not.cpp
*/

#include "criterion/criterion.h"
#include "NotComponent.hpp"
#include "InputComponent.hpp"

Test(not_component, first_value_test) {
    nts::NotComponent notComponent("NOT");

    cr_assert_eq(notComponent.compute(1), nts::Tristate::Undefined);
}

Test(not_component, compute_test_1) {
    nts::NotComponent notComponent("NOT");
    nts::InputComponent inputComponent("INPUT");

    inputComponent.setNextValue(nts::Tristate::True);
    inputComponent.simulate(1);
    notComponent.setLink(1, inputComponent, 1);
    cr_assert_eq(notComponent.compute(1), nts::Tristate::False);
}

Test(not_component, compute_test_2) {
    nts::NotComponent notComponent("NOT");
    nts::InputComponent inputComponent("INPUT");

    inputComponent.setNextValue(nts::Tristate::False);
    inputComponent.simulate(1);
    inputComponent.simulate(1);
    notComponent.setLink(1, inputComponent, 1);
    cr_assert_eq(notComponent.compute(1), nts::Tristate::True);
}

Test(not_component, compute_test_3) {
    nts::NotComponent notComponent("NOT");
    nts::InputComponent inputComponent("INPUT");

    inputComponent.setNextValue(nts::Tristate::Undefined);
    inputComponent.simulate(1);
    notComponent.setLink(1, inputComponent, 1);
    cr_assert_eq(notComponent.compute(1), nts::Tristate::Undefined);
}
