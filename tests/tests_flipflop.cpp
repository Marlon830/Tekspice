/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_flipflop.cpp
*/

#include "criterion/criterion.h"
#include "FlipFlopComponent.hpp"
#include "InputComponent.hpp"

Test(flipflop_component, compute_test_1) {
    nts::FlipFlopComponent flipFlopComponent("FLIPFLOP");
    nts::InputComponent inputComponent1("input");
    nts::InputComponent inputComponent2("input");
    nts::InputComponent inputComponent3("input");
    nts::InputComponent inputComponent4("input");

    inputComponent1.setNextValue(nts::Tristate::True);
    inputComponent1.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::True);
    inputComponent2.simulate(1);
    inputComponent3.setNextValue(nts::Tristate::True);
    inputComponent3.simulate(1);
    inputComponent4.setNextValue(nts::Tristate::True);
    inputComponent4.simulate(1);
    flipFlopComponent.setLink(3, inputComponent1, 1);
    flipFlopComponent.setLink(4, inputComponent2, 1);
    flipFlopComponent.setLink(5, inputComponent3, 1);
    flipFlopComponent.setLink(6, inputComponent4, 1);

    cr_assert_eq(flipFlopComponent.compute(1), nts::Tristate::True);
    cr_assert_eq(flipFlopComponent.compute(2), nts::Tristate::True);
}

Test(flipflop_component, compute_test_2) {
    nts::FlipFlopComponent flipFlopComponent("FLIPFLOP");
    nts::InputComponent clock("input");
    nts::InputComponent reset("input");
    nts::InputComponent data("input");
    nts::InputComponent set("input");

    clock.setNextValue(nts::Tristate::True);
    clock.simulate(1);
    reset.setNextValue(nts::Tristate::False);
    reset.simulate(1);
    data.setNextValue(nts::Tristate::False);
    data.simulate(1);
    set.setNextValue(nts::Tristate::False);
    set.simulate(1);
    flipFlopComponent.setLink(3, clock, 1);
    flipFlopComponent.setLink(4, reset, 1);
    flipFlopComponent.setLink(5, data, 1);
    flipFlopComponent.setLink(6, set, 1);

    cr_assert_eq(flipFlopComponent.compute(1), nts::Tristate::False);
    cr_assert_eq(flipFlopComponent.compute(2), nts::Tristate::True);
}

Test(flipflop_component, compute_test_3) {
    nts::FlipFlopComponent flipFlopComponent("FLIPFLOP");
    nts::InputComponent clock("input");
    nts::InputComponent reset("input");
    nts::InputComponent data("input");
    nts::InputComponent set("input");

    clock.setNextValue(nts::Tristate::True);
    clock.simulate(1);
    reset.setNextValue(nts::Tristate::False);
    reset.simulate(1);
    data.setNextValue(nts::Tristate::True);
    data.simulate(1);
    set.setNextValue(nts::Tristate::False);
    set.simulate(1);
    flipFlopComponent.setLink(3, clock, 1);
    flipFlopComponent.setLink(4, reset, 1);
    flipFlopComponent.setLink(5, data, 1);
    flipFlopComponent.setLink(6, set, 1);

    cr_assert_eq(flipFlopComponent.compute(1), nts::Tristate::True);
    cr_assert_eq(flipFlopComponent.compute(2), nts::Tristate::False);
}

Test(flipflop_component, compute_test_4) {
    nts::FlipFlopComponent flipFlopComponent("FLIPFLOP");
    nts::InputComponent clock("input");
    nts::InputComponent reset("input");
    nts::InputComponent set("input");

    clock.setNextValue(nts::Tristate::False);
    clock.simulate(1);
    reset.setNextValue(nts::Tristate::False);
    reset.simulate(1);
    set.setNextValue(nts::Tristate::False);
    set.simulate(1);
    flipFlopComponent.setLink(3, clock, 1);
    flipFlopComponent.setLink(4, reset, 1);
    flipFlopComponent.setLink(6, set, 1);

    cr_assert_eq(flipFlopComponent.compute(1), nts::Tristate::Undefined);
    cr_assert_eq(flipFlopComponent.compute(2), nts::Tristate::Undefined);
}

Test(flipflop_component, compute_test_5) {
    nts::FlipFlopComponent flipFlopComponent("FLIPFLOP");
    nts::InputComponent reset("input");
    nts::InputComponent set("input");

    reset.setNextValue(nts::Tristate::True);
    reset.simulate(1);
    set.setNextValue(nts::Tristate::False);
    set.simulate(1);
    flipFlopComponent.setLink(4, reset, 1);
    flipFlopComponent.setLink(6, set, 1);

    cr_assert_eq(flipFlopComponent.compute(1), nts::Tristate::False);
    cr_assert_eq(flipFlopComponent.compute(2), nts::Tristate::True);
}

Test(flipflop_component, compute_test_6) {
    nts::FlipFlopComponent flipFlopComponent("FLIPFLOP");
    nts::InputComponent reset("input");
    nts::InputComponent set("input");

    reset.setNextValue(nts::Tristate::False);
    reset.simulate(1);
    set.setNextValue(nts::Tristate::True);
    set.simulate(1);
    flipFlopComponent.setLink(4, reset, 1);
    flipFlopComponent.setLink(6, set, 1);

    cr_assert_eq(flipFlopComponent.compute(1), nts::Tristate::True);
    cr_assert_eq(flipFlopComponent.compute(2), nts::Tristate::False);
}

Test(flipflop_component, compute_test_7) {
    nts::FlipFlopComponent flipFlopComponent("FLIPFLOP");

    cr_assert_eq(flipFlopComponent.compute(1), nts::Tristate::Undefined);
    cr_assert_eq(flipFlopComponent.compute(2), nts::Tristate::Undefined);
}
