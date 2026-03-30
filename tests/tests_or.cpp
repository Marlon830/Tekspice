/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_or.cpp
*/

#include <criterion/criterion.h>
#include "OrComponent.hpp"
#include "InputComponent.hpp"

Test(or_component, compute_test_1) {
    nts::OrComponent orComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::True);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::True);
    inputComponent2.simulate(1);
    orComponent.setLink(1, inputComponent1, 1);
    orComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(orComponent.compute(1), nts::Tristate::True);
}

Test(or_component, compute_test_2) {
    nts::OrComponent orComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::False);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::True);
    inputComponent2.simulate(1);
    orComponent.setLink(1, inputComponent1, 1);
    orComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(orComponent.compute(1), nts::Tristate::True);
}

Test(or_component, compute_test_3) {
    nts::OrComponent orComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::False);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::False);
    inputComponent2.simulate(1);
    orComponent.setLink(1, inputComponent1, 1);
    orComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(orComponent.compute(1), nts::Tristate::False);
}

Test(or_component, compute_test_4) {
    nts::OrComponent orComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::Undefined);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::True);
    inputComponent2.simulate(1);
    orComponent.setLink(1, inputComponent1, 1);
    orComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(orComponent.compute(1), nts::Tristate::True);
}

Test(or_component, compute_test_5) {
    nts::OrComponent orComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::False);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::Undefined);
    inputComponent2.simulate(1);
    orComponent.setLink(1, inputComponent1, 1);
    orComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(orComponent.compute(1), nts::Tristate::Undefined);
}

Test(or_component, compute_test_6_two_undefined) {
    nts::OrComponent orComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::Undefined);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::Undefined);
    inputComponent2.simulate(1);
    orComponent.setLink(1, inputComponent1, 1);
    orComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(orComponent.compute(1), nts::Tristate::Undefined);
}
