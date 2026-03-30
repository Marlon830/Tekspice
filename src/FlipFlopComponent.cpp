/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** FlipFlopComponent.cpp
*/

#include "FlipFlopComponent.hpp"

nts::FlipFlopComponent::FlipFlopComponent(std::string name)
{
    this->_name = name;
}

nts::Tristate nts::FlipFlopComponent::compute(std::size_t pin)
{
    nts::Tristate clock = nts::Tristate::Undefined;
    nts::Tristate reset = nts::Tristate::Undefined;
    nts::Tristate data = nts::Tristate::Undefined;
    nts::Tristate set = nts::Tristate::Undefined;

    if (this->_links[3].component != nullptr) {
        clock = this->_links[3].component->compute(this->_links[3].pin);
    }
    if (this->_links[4].component != nullptr) {
        reset = this->_links[4].component->compute(this->_links[4].pin);
    }
    if (this->_links[5].component != nullptr) {
        data = this->_links[5].component->compute(this->_links[5].pin);
    }
    if (this->_links[6].component != nullptr) {
        set = this->_links[6].component->compute(this->_links[6].pin);
    }
    if (set == nts::Tristate::False && reset == nts::Tristate::False && data == nts::Tristate::False && clock == nts::Tristate::True) {
        if (pin == 1) {
            _output1 = nts::Tristate::False;
            return nts::Tristate::False;
        }
        if (pin == 2) {
            _output2 = nts::Tristate::True;
            return nts::Tristate::True;
        }
    }
    if (set == nts::Tristate::False && reset == nts::Tristate::False && data == nts::Tristate::True && clock == nts::Tristate::True) {
        if (pin == 1) {
            _output1 = nts::Tristate::True;
            return nts::Tristate::True;
        }
        if (pin == 2) {
            _output2 = nts::Tristate::False;
            return nts::Tristate::False;
        }
    }
    if (set == nts::Tristate::False && reset == nts::Tristate::False && clock == nts::Tristate::False) {
        if (pin == 1) {
            return _output1;
        }
        if (pin == 2) {
            return _output2;
        }
    }
    if (set == nts::Tristate::False && reset == nts::Tristate::True) {
        if (pin == 1) {
            _output1 = nts::Tristate::False;
            return nts::Tristate::False;
        }
        if (pin == 2) {
            _output2 = nts::Tristate::True;
            return nts::Tristate::True;
        }
    }
    if (set == nts::Tristate::True && reset == nts::Tristate::False) {
        if (pin == 1) {
            _output1 = nts::Tristate::True;
            return nts::Tristate::True;
        }
        if (pin == 2) {
            _output2 = nts::Tristate::False;
            return nts::Tristate::False;
        }
    }
    if (set == nts::Tristate::True && reset == nts::Tristate::True) {
        if (pin == 1) {
            _output1 = nts::Tristate::True;
            return nts::Tristate::True;
        }
        if (pin == 2) {
            _output2 = nts::Tristate::True;
            return nts::Tristate::True;
        }
    }
    return nts::Tristate::Undefined;
}
