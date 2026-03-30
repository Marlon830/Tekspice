/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** Circuit.hpp
*/

#pragma once

#include <vector>
#include "AComponent.hpp"
#include "IComponent.hpp"

namespace nts
{
    class Circuit : public AComponent
    {
    public:
        nts::Tristate compute(std::size_t pin) override;
        const size_t &getTick() const;
        void setTick(const size_t &tick);
        const std::map<std::string, IComponent *> &getInputs() const;
        const std::map<std::string, IComponent *> &getOutputs() const;
        void setInput(const std::string &name, nts::Tristate value);
        void addInput(const std::string &name, IComponent *component);
        void addOutput(const std::string &name, IComponent *component);

        std::map<std::size_t, IComponent *> getInputsMapPins() const;
        std::map<std::size_t, IComponent *> getOutputsMapPins() const;
        void setInputsMapPins(std::map<std::size_t, IComponent *> inputsMapPins);
        void setOutputsMapPins(std::map<std::size_t, IComponent *> outputsMapPins);
    private:
        std::map<std::string, IComponent *> _inputs;
        std::map<std::string, IComponent *> _outputs;
        std::map<std::size_t, IComponent *> _outputsMapPins;
        std::map<std::size_t, IComponent *> _inputsMapPins;
        size_t _tick = 0;
    };
}
