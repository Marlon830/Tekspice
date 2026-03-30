/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** TrueComponent.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class TrueComponent : public AComponent
    {
    public:
        TrueComponent(std::string name);
        nts::Tristate compute(std::size_t pin) override;
    };
}
