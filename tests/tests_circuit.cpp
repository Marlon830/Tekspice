/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_circuit.cpp
*/

#include "criterion/criterion.h"
#include "Circuit.hpp"
#include "Parser.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "Simulation.hpp"

Test(circuit, test_circuit)
{
    nts::Parser *parser = new nts::Parser();
    nts::InputComponent inputComponent("input");
    nts::InputComponent inputComponent2("input2");
    nts::OutputComponent outputComponent("output");
    nts::Circuit circuit(parser->parse("./src/GateComponents/nor.nts"));

    inputComponent.setNextValue(nts::Tristate::False);
    inputComponent.simulate(1);
    inputComponent2.setNextValue(nts::Tristate::True);
    inputComponent2.simulate(1);
    outputComponent.setLink(1, inputComponent, 1);

    std::map<std::size_t, nts::IComponent *> inputsMapPins;
    inputsMapPins[1] = &inputComponent;
    inputsMapPins[2] = &inputComponent2;

    std::map<std::size_t, nts::IComponent *> outputsMapPins;
    outputsMapPins[1] = &outputComponent;

    circuit.setInputsMapPins(inputsMapPins);
    circuit.setOutputsMapPins(outputsMapPins);

    std::map<std::size_t, nts::IComponent *> inputsMapPins2 = circuit.getInputsMapPins();
    std::map<std::size_t, nts::IComponent *> outputsMapPins2 = circuit.getOutputsMapPins();
    cr_assert_eq(inputsMapPins2[1]->getName(), "input");
    cr_assert_eq(outputsMapPins2[1]->getName(), "output");

    circuit.addOutput("output", &outputComponent);
    circuit.addInput("input", &inputComponent);
    circuit.addInput("input2", &inputComponent2);
    circuit.setName("Nor");
    circuit.setTick(0);
    cr_assert_eq(circuit.getName(), "Nor");
    nts::Simulation::maxActualTick += 1;
    cr_assert_eq(circuit.compute(1), nts::Tristate::False);
    cr_assert_eq(circuit.getTick(), 0);
    std::map<std::string, nts::IComponent *> inputs = circuit.getInputs();
    std::map<std::string, nts::IComponent *> outputs = circuit.getOutputs();
    cr_assert_str_eq(inputs["input"]->getName().c_str(), "input");
    cr_assert_str_eq(outputs["output"]->getName().c_str(), "output");

    circuit.setInput("input", nts::Tristate::False);
    circuit.setInput("input2", nts::Tristate::False);
    inputs["input"]->simulate(1);
    inputs["input2"]->simulate(1);
    nts::Simulation::maxActualTick += 1;
    cr_assert_eq(circuit.compute(1), nts::Tristate::False);
}
