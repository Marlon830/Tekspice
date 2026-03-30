/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** LoggerComponent.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class LoggerComponent : public AComponent
    {
    public:
        LoggerComponent(std::string name);
        nts::Tristate compute(__attribute__((unused)) std::size_t pin) override { return nts::Tristate::Undefined; };
        void simulate(std::size_t tick) override;
    };
}
