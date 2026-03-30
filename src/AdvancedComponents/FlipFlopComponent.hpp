/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** FlipFlopComponent.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class FlipFlopComponent : public AComponent
    {
    public:
        FlipFlopComponent(std::string name);
        nts::Tristate compute(std::size_t pin) override;
    private:
        nts::Tristate _output1 = nts::Tristate::Undefined;
        nts::Tristate _output2 = nts::Tristate::Undefined;
    };
}
