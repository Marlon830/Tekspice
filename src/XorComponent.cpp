/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** XorComponent.cpp
*/

#include "XorComponent.hpp"

nts::XorComponent::XorComponent(std::string name)
{
    this->_name = name;
}

nts::Tristate nts::XorComponent::compute(__attribute__((unused)) std::size_t pin)
{
    nts::Tristate firstInput = nts::Tristate::Undefined;
    nts::Tristate secondInput = nts::Tristate::Undefined;

    if (this->_links[1].component != nullptr) {
        firstInput = this->_links[1].component->compute(this->_links[1].pin);
    }
    if (this->_links[2].component != nullptr) {
        secondInput = this->_links[2].component->compute(this->_links[2].pin);
    }

    if (firstInput == nts::Tristate::Undefined || secondInput == nts::Tristate::Undefined) {
        return nts::Tristate::Undefined;
    }

    return (firstInput ^ secondInput) == nts::Tristate::True ? nts::Tristate::True : nts::Tristate::False;
}
