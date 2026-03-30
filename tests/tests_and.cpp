/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_and.cpp
*/

#include <criterion/criterion.h>
#include "AndComponent.hpp"
#include "InputComponent.hpp"

Test(and_component, compute_test_1) {
    nts::AndComponent andComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::True);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::True);
    inputComponent2.simulate(1);
    andComponent.setLink(1, inputComponent1, 1);
    andComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(andComponent.compute(1), nts::Tristate::True);
}

Test(and_component, compute_test_2) {
    nts::AndComponent andComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::False);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::True);
    inputComponent2.simulate(1);
    andComponent.setLink(1, inputComponent1, 1);
    andComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(andComponent.compute(1), nts::Tristate::False);
}

Test(and_component, compute_test_3) {
    nts::AndComponent andComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::False);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::False);
    inputComponent2.simulate(1);
    andComponent.setLink(1, inputComponent1, 1);
    andComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(andComponent.compute(1), nts::Tristate::False);
}

Test(and_component, compute_test_4) {
    nts::AndComponent andComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::Undefined);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::True);
    inputComponent2.simulate(1);
    andComponent.setLink(1, inputComponent1, 1);
    andComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(andComponent.compute(1), nts::Tristate::Undefined);
}

Test(and_component, compute_test_5) {
    nts::AndComponent andComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::False);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::Undefined);
    inputComponent2.simulate(1);
    andComponent.setLink(1, inputComponent1, 1);
    andComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(andComponent.compute(1), nts::Tristate::False);
}

Test(and_component, compute_test_6) {
    nts::AndComponent andComponent("AND");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");

    inputComponent1.setNextValue(nts::Tristate::Undefined);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::Undefined);
    inputComponent2.simulate(1);
    andComponent.setLink(1, inputComponent1, 1);
    andComponent.setLink(2, inputComponent2, 1);

    cr_assert_eq(andComponent.compute(1), nts::Tristate::Undefined);
}
