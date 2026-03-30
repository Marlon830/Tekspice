/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** OutputComponent.cpp
*/

#include "OutputComponent.hpp"
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"
#include "Simulation.hpp"

nts::OutputComponent::OutputComponent(std::string name)
{
    this->_name = name;
}

nts::Tristate nts::OutputComponent::compute(std::size_t pin)
{
    for (auto &link : this->_links) {
        if (link.second.component != nullptr) {
            if (dynamic_cast<OutputComponent *>(link.second.component) != nullptr) {
                if (this->_actualTick >= nts::Simulation::maxActualTick) {
                    return this->_value;
                }
                this->_actualTick += 1;
                this->_value = link.second.component->compute(link.second.pin);
                return this->_value;
            }
        }
    }
    if (this->_actualTick >= nts::Simulation::maxActualTick &&
    dynamic_cast<TrueComponent *>(this->_links[pin].component) == nullptr &&
    dynamic_cast<FalseComponent *>(this->_links[pin].component) == nullptr) {
        return this->_value;
    }
    if (this->_links[pin].component == nullptr) {
        this->_value = nts::Tristate::Undefined;
        this->_actualTick += 1;
        return this->_value;
    }
    this->_actualTick += 1;
    this->_value = this->_links[pin].component->compute(this->_links[pin].pin);
    return this->_value;
}
