/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** OutputComponent.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class OutputComponent : public AComponent
    {
    public:
        OutputComponent(std::string name);
        nts::Tristate compute(std::size_t pin) override;
    private:
        nts::Tristate _value = nts::Tristate::Undefined;
    };
}
