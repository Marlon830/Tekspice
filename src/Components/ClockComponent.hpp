/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** ClockComponent.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class ClockComponent : public AComponent
    {
    public:
        ClockComponent(std::string name);
        void simulate(std::size_t tick) override;
        nts::Tristate compute(std::size_t pin) override;
        void setNextValue(nts::Tristate nextValue) override;

    private:
        nts::Tristate _value;
        nts::Tristate _nextValue;
    };
}
