/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** 4514Component.cpp
*/

#include "LoggerComponent.hpp"
#include <fstream>
#include <array>

nts::LoggerComponent::LoggerComponent(std::string name)
{
    this->_name = name;
}

void nts::LoggerComponent::simulate(__attribute__((unused)) std::size_t tick)
{
    std::array<nts::Tristate, 9> inputs;
    nts::Tristate clock = nts::Tristate::Undefined;
    nts::Tristate inhibit = nts::Tristate::Undefined;

    for (int i = 1; i <= 8; i++) {
        inputs[i] = nts::Tristate::Undefined;
    }
    if (this->_links[10].component != nullptr) {
        inhibit = this->_links[10].component->compute(this->_links[10].pin);
    }
    if (inhibit == nts::Tristate::True || inhibit == nts::Tristate::Undefined) {
        return;
    }
    if (this->_links[9].component != nullptr) {
        clock = this->_links[9].component->compute(this->_links[9].pin);
    }
    if (clock == nts::Tristate::False || clock == nts::Tristate::Undefined) {
        return;
    }
    for (int i = 1; i <= 8; i++) {
        inputs[i] = this->_links[i].component->compute(this->_links[i].pin);
    }
    for (int i = 1; i <= 8; i++) {
        if (inputs[i] == nts::Tristate::Undefined) {
            return;
        }
    }

    char input = (inputs[1] == nts::Tristate::True ? 1 : 0) |
                (inputs[2] == nts::Tristate::True ? 1 : 0) << 1 |
                (inputs[3] == nts::Tristate::True ? 1 : 0) << 2 |
                (inputs[4] == nts::Tristate::True ? 1 : 0) << 3 |
                (inputs[5] == nts::Tristate::True ? 1 : 0) << 4 |
                (inputs[6] == nts::Tristate::True ? 1 : 0) << 5 |
                (inputs[7] == nts::Tristate::True ? 1 : 0) << 6 |
                (inputs[8] == nts::Tristate::True ? 1 : 0) << 7;

    std::ofstream file("./log.bin", std::ios::app);
    file << input;
    file.close();

    return;
}
