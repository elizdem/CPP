#include "Multiplier.h"

Multiplier::Multiplier() :
	ExpressionEvaluator() {
	symbol = '*';
}

Multiplier::Multiplier(int numOfOperands) :
	ExpressionEvaluator(numOfOperands) {
	symbol = '*';
}

bool Multiplier::containZeros() {
	for (int i = 0; i < numOfOperands; ++i) {
		if (operands[i] == 0) return true;
	}
	return false;
}

double Multiplier::calculate() {
	if (containZeros()) return 0;

	double result = operands[0];

	for (int i = 1; i < numOfOperands; ++i) {
		result *= operands[i];
	}

	return result;
}