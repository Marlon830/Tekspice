/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_4514.cpp
*/

#include "criterion/criterion.h"
#include "4514Component.hpp"
#include "InputComponent.hpp"

Test(C4514Component, compute_test)
{
    nts::C4514Component component("test");
    nts::InputComponent input1("input");
    nts::InputComponent input2("input");
    nts::InputComponent input3("input");
    nts::InputComponent input4("input");
    nts::InputComponent strobe("input");
    nts::InputComponent inhibit("input");

    input1.setNextValue(nts::Tristate::Undefined);
    input2.setNextValue(nts::Tristate::Undefined);
    input3.setNextValue(nts::Tristate::Undefined);
    input4.setNextValue(nts::Tristate::Undefined);
    strobe.setNextValue(nts::Tristate::True);
    inhibit.setNextValue(nts::Tristate::False);
    input1.simulate(1);
    input2.simulate(1);
    input3.simulate(1);
    input4.simulate(1);
    strobe.simulate(1);
    inhibit.simulate(1);
    component.setLink(1, strobe, 1);
    component.setLink(23, inhibit, 1);
    component.setLink(2, input1, 1);
    component.setLink(3, input2, 1);
    component.setLink(21, input3, 1);
    component.setLink(22, input4, 1);

    cr_assert_eq(component.compute(11), nts::Tristate::Undefined);
}

Test(C4514Component, compute_test_2)
{
    nts::C4514Component component("test");
    nts::InputComponent input1("input");
    nts::InputComponent input2("input");
    nts::InputComponent input3("input");
    nts::InputComponent input4("input");
    nts::InputComponent strobe("input");
    nts::InputComponent inhibit("input");

    input1.setNextValue(nts::Tristate::True);
    input2.setNextValue(nts::Tristate::True);
    input3.setNextValue(nts::Tristate::True);
    input4.setNextValue(nts::Tristate::True);
    strobe.setNextValue(nts::Tristate::True);
    inhibit.setNextValue(nts::Tristate::False);
    input1.simulate(1);
    input2.simulate(1);
    input3.simulate(1);
    input4.simulate(1);
    strobe.simulate(1);
    inhibit.simulate(1);
    component.setLink(1, strobe, 1);
    component.setLink(23, inhibit, 1);
    component.setLink(2, input1, 1);
    component.setLink(3, input2, 1);
    component.setLink(21, input3, 1);
    component.setLink(22, input4, 1);

    cr_assert_eq(component.compute(15), nts::Tristate::True);
    cr_assert_eq(component.compute(14), nts::Tristate::False);
}

Test(C4514Component, strobe_test)
{
    nts::C4514Component component("test");
    nts::InputComponent input1("input");
    nts::InputComponent input2("input");
    nts::InputComponent input3("input");
    nts::InputComponent input4("input");
    nts::InputComponent strobe("input");
    nts::InputComponent inhibit("input");

    input1.setNextValue(nts::Tristate::True);
    input2.setNextValue(nts::Tristate::True);
    input3.setNextValue(nts::Tristate::True);
    input4.setNextValue(nts::Tristate::True);
    strobe.setNextValue(nts::Tristate::True);
    inhibit.setNextValue(nts::Tristate::False);
    input1.simulate(1);
    input2.simulate(1);
    input3.simulate(1);
    input4.simulate(1);
    strobe.simulate(1);
    inhibit.simulate(1);
    component.setLink(1, strobe, 1);
    component.setLink(23, inhibit, 1);
    component.setLink(2, input1, 1);
    component.setLink(3, input2, 1);
    component.setLink(21, input3, 1);
    component.setLink(22, input4, 1);

    cr_assert_eq(component.compute(15), nts::Tristate::True);
    strobe.setNextValue(nts::Tristate::False);
    strobe.simulate(1);
    input4.setNextValue(nts::Tristate::False);
    input4.simulate(1);
    cr_assert_eq(component.compute(15), nts::Tristate::True);
}

Test(C4514Component, inhibit_test)
{
    nts::C4514Component component("test");
    nts::InputComponent input1("input");
    nts::InputComponent input2("input");
    nts::InputComponent input3("input");
    nts::InputComponent input4("input");
    nts::InputComponent strobe("input");
    nts::InputComponent inhibit("input");

    input1.setNextValue(nts::Tristate::True);
    input2.setNextValue(nts::Tristate::True);
    input3.setNextValue(nts::Tristate::True);
    input4.setNextValue(nts::Tristate::True);
    strobe.setNextValue(nts::Tristate::True);
    inhibit.setNextValue(nts::Tristate::True);
    input1.simulate(1);
    input2.simulate(1);
    input3.simulate(1);
    input4.simulate(1);
    strobe.simulate(1);
    inhibit.simulate(1);
    component.setLink(1, strobe, 1);
    component.setLink(23, inhibit, 1);
    component.setLink(2, input1, 1);
    component.setLink(3, input2, 1);
    component.setLink(21, input3, 1);
    component.setLink(22, input4, 1);

    cr_assert_eq(component.compute(15), nts::Tristate::False);
}
