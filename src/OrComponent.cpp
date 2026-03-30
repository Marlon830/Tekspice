/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** OrComponent.cpp
*/

#include "OrComponent.hpp"

nts::OrComponent::OrComponent(std::string name)
{
    this->_name = name;
}

nts::Tristate nts::OrComponent::compute(__attribute__((unused)) std::size_t pin)
{
    nts::Tristate firstInput = nts::Tristate::Undefined;
    nts::Tristate secondInput = nts::Tristate::Undefined;

    if (this->_links[1].component != nullptr) {
        firstInput = this->_links[1].component->compute(this->_links[1].pin);
    }
    if (this->_links[2].component != nullptr) {
        secondInput = this->_links[2].component->compute(this->_links[2].pin);
    }

    if ((firstInput == nts::Tristate::True && secondInput == nts::Tristate::Undefined) ||
    (firstInput == nts::Tristate::Undefined && secondInput == nts::Tristate::True)) {
        return nts::Tristate::True;
    }
    if ((firstInput == nts::Tristate::False && secondInput == nts::Tristate::Undefined) ||
    (firstInput == nts::Tristate::Undefined && secondInput == nts::Tristate::False) ||
    (firstInput == nts::Tristate::Undefined && secondInput == nts::Tristate::Undefined)) {
        return nts::Tristate::Undefined;
    }

    return (firstInput || secondInput) == nts::Tristate::True ? nts::Tristate::True : nts::Tristate::False;
}
