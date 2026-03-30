/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** Circuit.cpp
*/

#include "Circuit.hpp"

nts::Tristate nts::Circuit::compute(std::size_t pin)
{
    return this->_outputsMapPins[pin]->compute(1);
}

const size_t &nts::Circuit::getTick() const
{
    return this->_tick;
}

void nts::Circuit::setTick(const size_t &tick)
{
    this->_tick = tick;
}

const std::map<std::string, nts::IComponent *> &nts::Circuit::getInputs() const
{
    return this->_inputs;
}

const std::map<std::string, nts::IComponent *> &nts::Circuit::getOutputs() const
{
    return this->_outputs;
}

void nts::Circuit::setInput(const std::string &name, nts::Tristate value)
{
    if (this->_inputs.find(name) == this->_inputs.end())
        return;
    this->_inputs[name]->setNextValue(value);
}

void nts::Circuit::addInput(const std::string &name, nts::IComponent *component)
{
    this->_inputs[name] = component;
}

void nts::Circuit::addOutput(const std::string &name, nts::IComponent *component)
{
    this->_outputs[name] = component;
}

std::map<std::size_t, nts::IComponent *> nts::Circuit::getInputsMapPins() const
{
    return this->_inputsMapPins;
}

std::map<std::size_t, nts::IComponent *> nts::Circuit::getOutputsMapPins() const
{
    return this->_outputsMapPins;
}

void nts::Circuit::setInputsMapPins(std::map<std::size_t, IComponent *> inputsMapPins)
{
    this->_inputsMapPins = inputsMapPins;
}

void nts::Circuit::setOutputsMapPins(std::map<std::size_t, IComponent *> outputsMapPins)
{
    this->_outputsMapPins = outputsMapPins;
}
