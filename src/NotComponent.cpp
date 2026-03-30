/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** NotComponent.cpp
*/

#include "NotComponent.hpp"

nts::NotComponent::NotComponent(std::string name)
{
    this->_name = name;
}

nts::Tristate nts::NotComponent::compute(__attribute__((unused)) std::size_t pin)
{
    nts::Tristate input = nts::Tristate::Undefined;

    if (this->_links[1].component == nullptr)
        return nts::Tristate::Undefined;
    input = this->_links[1].component->compute(this->_links[1].pin);
    if (input == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    return (input == nts::Tristate::True) ? nts::Tristate::False : nts::Tristate::True;
}
