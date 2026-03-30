/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** InputComponent.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class InputComponent : public AComponent
    {
    public:
        InputComponent(std::string name);
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setNextValue(nts::Tristate nextValue) override;
        void switchLinkedToCircuit();

    private:
        nts::Tristate _value;
        nts::Tristate _nextValue;
        bool _isLinkedToCircuit = false;
    };
}
