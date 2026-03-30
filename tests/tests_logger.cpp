/*
** EPITECH PROJECT, 2023
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** tests_logger.cpp
*/

#include "criterion/criterion.h"
#include "LoggerComponent.hpp"

Test(logger, compute_test)
{
    nts::LoggerComponent logger("test");

    cr_assert_eq(logger.compute(1), nts::Tristate::Undefined);
}
