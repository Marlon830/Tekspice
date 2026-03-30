/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** ClockComponent.cpp
*/

#include "ClockComponent.hpp"

nts::ClockComponent::ClockComponent(std::string name)
{
    this->_name = name;
    this->_value = nts::Tristate::Undefined;
    this->_nextValue = nts::Tristate::Undefined;
}

void nts::ClockComponent::simulate(__attribute__((unused)) std::size_t tick)
{
    this->_value = this->_nextValue;
    if (this->_value == nts::Tristate::True)
        this->_nextValue = nts::Tristate::False;
    else if (this->_value == nts::Tristate::False)
        this->_nextValue = nts::Tristate::True;
}

nts::Tristate nts::ClockComponent::compute(__attribute__((unused)) std::size_t pin)
{
    for (auto &link : this->_links) {
        if (link.second.component != nullptr) {
            if (dynamic_cast<ClockComponent *>(link.second.component) != nullptr) {
                this->_value = link.second.component->compute(link.second.pin);
                return this->_value;
            }
        }
    }
    return this->_value;
}

void nts::ClockComponent::setNextValue(nts::Tristate nextValue)
{
    this->_nextValue = nextValue;
}