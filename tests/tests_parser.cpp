/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_parser.cpp
*/

#include "criterion/criterion.h"
#include "Parser.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include "Simulation.hpp"

Test(parser, test_duplicate_name)
{
    pid_t pid = fork();

    if (pid == 0) {
        nts::Parser parser;
        parser.parse("tests/tests_nts_duplicate_name.nts");
        exit(0);
    } else {
        int status = 0;
        waitpid(pid, &status, 0);
        cr_assert_eq(WEXITSTATUS(status), 84);
    }
}

Test(parser, test_empty_file)
{
    pid_t pid = fork();

    if (pid == 0) {
        nts::Parser parser;
        parser.parse("tests/tests_nts_empty_file.nts");
        exit(0);
    } else {
        int status = 0;
        waitpid(pid, &status, 0);
        cr_assert_eq(WEXITSTATUS(status), 84);
    }
}

Test(parser, test_empty_pin)
{
    pid_t pid = fork();

    if (pid == 0) {
        nts::Parser parser;
        parser.parse("tests/tests_nts_empty_pin.nts");
        exit(0);
    } else {
        int status = 0;
        waitpid(pid, &status, 0);
        cr_assert_eq(WEXITSTATUS(status), 84);
    }
}

Test(parser, test_missing_link)
{
    pid_t pid = fork();

    if (pid == 0) {
        nts::Parser parser;
        parser.parse("tests/tests_nts_missing_links.nts");
        exit(0);
    } else {
        int status = 0;
        waitpid(pid, &status, 0);
        cr_assert_eq(WEXITSTATUS(status), 0);
    }
}

Test(parser, test_no_component_name)
{
    pid_t pid = fork();

    if (pid == 0) {
        nts::Parser parser;
        parser.parse("tests/tests_nts_no_component_name.nts");
        exit(0);
    } else {
        int status = 0;
        waitpid(pid, &status, 0);
        cr_assert_eq(WEXITSTATUS(status), 84);
    }
}

Test(parser, test_no_component)
{
    pid_t pid = fork();

    if (pid == 0) {
        nts::Parser parser;
        parser.parse("tests/tests_nts_no_component.nts");
        exit(0);
    } else {
        int status = 0;
        waitpid(pid, &status, 0);
        cr_assert_eq(WEXITSTATUS(status), 84);
    }
}

Test(parser, test_unknown_component)
{
    pid_t pid = fork();

    if (pid == 0) {
        nts::Parser parser;
        parser.parse("tests/tests_nts_unknown_component.nts");
        exit(0);
    } else {
        int status = 0;
        waitpid(pid, &status, 0);
        cr_assert_eq(WEXITSTATUS(status), 84);
    }
}

Test(parser, test_basic_nor)
{
    nts::Parser parser;
    nts::Circuit *circuit = dynamic_cast<nts::Circuit *>(parser.createComponent("nor").release());

    for (auto &input : circuit->getInputs()) {
        input.second->setNextValue(nts::Tristate::True);
        input.second->simulate(1);
    }

    nts::Simulation::maxActualTick += 1;
    for (auto &output : circuit->getOutputs()) {
        cr_assert_eq(output.second->compute(1), nts::Tristate::False);
    }
}

Test(parser, test_basic_nand)
{
    nts::Parser parser;
    nts::Circuit *circuit = dynamic_cast<nts::Circuit *>(parser.createComponent("nand").release());

    for (auto &input : circuit->getInputs()) {
        input.second->setNextValue(nts::Tristate::True);
        input.second->simulate(1);
    }

    nts::Simulation::maxActualTick += 1;
    for (auto &output : circuit->getOutputs()) {
        cr_assert_eq(output.second->compute(1), nts::Tristate::False);
    }
}

Test(parser, test_basic_4001)
{
    nts::Parser parser;
    nts::Circuit *circuit = dynamic_cast<nts::Circuit *>(parser.createComponent("4001").release());

    for (auto &input : circuit->getInputs()) {
        input.second->setNextValue(nts::Tristate::True);
        input.second->simulate(1);
    }

    nts::Simulation::maxActualTick += 1;
    for (auto &output : circuit->getOutputs()) {
        cr_assert_eq(output.second->compute(1), nts::Tristate::False);
    }
}

Test(parser, test_basic_4081)
{
    nts::Parser parser;
    nts::Circuit *circuit = dynamic_cast<nts::Circuit *>(parser.createComponent("4081").release());

    for (auto &input : circuit->getInputs()) {
        input.second->setNextValue(nts::Tristate::True);
        input.second->simulate(1);
    }

    nts::Simulation::maxActualTick += 1;
    for (auto &output : circuit->getOutputs()) {
        cr_assert_eq(output.second->compute(1), nts::Tristate::True);
    }
}

Test(parser, test_basic_4071)
{
    nts::Parser parser;
    nts::Circuit *circuit = dynamic_cast<nts::Circuit *>(parser.createComponent("4071").release());

    for (auto &input : circuit->getInputs()) {
        input.second->setNextValue(nts::Tristate::True);
        input.second->simulate(1);
    }

    nts::Simulation::maxActualTick += 1;
    for (auto &output : circuit->getOutputs()) {
        cr_assert_eq(output.second->compute(1), nts::Tristate::True);
    }
}

Test(parser, test_basic_4011)
{
    nts::Parser parser;
    nts::Circuit *circuit = dynamic_cast<nts::Circuit *>(parser.createComponent("4011").release());

    for (auto &input : circuit->getInputs()) {
        input.second->setNextValue(nts::Tristate::True);
        input.second->simulate(1);
    }

    nts::Simulation::maxActualTick += 1;
    for (auto &output : circuit->getOutputs()) {
        cr_assert_eq(output.second->compute(1), nts::Tristate::False);
    }
}

Test(parser, test_basic_4030)
{
    nts::Parser parser;
    nts::Circuit *circuit = dynamic_cast<nts::Circuit *>(parser.createComponent("4030").release());

    for (auto &input : circuit->getInputs()) {
        input.second->setNextValue(nts::Tristate::True);
        input.second->simulate(1);
    }

    nts::Simulation::maxActualTick += 1;
    for (auto &output : circuit->getOutputs()) {
        cr_assert_eq(output.second->compute(1), nts::Tristate::False);
    }
}

Test(parser, test_basic_4069)
{
    nts::Parser parser;
    nts::Circuit *circuit = dynamic_cast<nts::Circuit *>(parser.createComponent("4069").release());

    for (auto &input : circuit->getInputs()) {
        input.second->setNextValue(nts::Tristate::True);
        input.second->simulate(1);
    }

    nts::Simulation::maxActualTick += 1;
    for (auto &output : circuit->getOutputs()) {
        cr_assert_eq(output.second->compute(1), nts::Tristate::False);
    }
}
