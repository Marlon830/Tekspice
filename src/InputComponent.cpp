/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** InputComponent.cpp
*/

#include "InputComponent.hpp"
#include "OutputComponent.hpp"

nts::InputComponent::InputComponent(std::string name)
{
    this->_name = name;
    this->_value = nts::Tristate::Undefined;
    this->_nextValue = nts::Tristate::Undefined;
}

void nts::InputComponent::simulate(__attribute__((unused)) std::size_t tick)
{
    this->_value = this->_nextValue;
}

nts::Tristate nts::InputComponent::compute(__attribute__((unused)) std::size_t pin)
{
    for (auto &link : this->_links) {
        if (link.second.component != nullptr) {
            if (dynamic_cast<InputComponent *>(link.second.component) != nullptr) {
                this->_value = link.second.component->compute(link.second.pin);
                return this->_value;
            }
            if (this->_isLinkedToCircuit) {
                if (dynamic_cast<OutputComponent *>(link.second.component) != nullptr) {
                    this->_value = link.second.component->compute(link.second.pin);
                    return this->_value;
                }
            }
        }
    }
    return this->_value;
}

void nts::InputComponent::setNextValue(nts::Tristate nextValue)
{
    this->_nextValue = nextValue;
}

void nts::InputComponent::switchLinkedToCircuit()
{
    this->_isLinkedToCircuit = !this->_isLinkedToCircuit;
}
