#include "Stack.h"
#include <string>
using namespace std;

bool isOperator(char);
bool isOpenBracket(char);
bool isCloseBracket(char);
bool isValidBracket(string);
bool isValidExpression(string);

int main()
{
	string exp;
	cout << "Enter any Expression: ";
	getline(cin, exp);

	if (isValidExpression(exp))
		cout << "Valid Expression\n";
	else
		cout << "Invalid Expression\n";

	return 0;
}

bool isValidExpression(string exp) {
	if (!isValidBracket(exp)) {
		cout << "\nInvalid Brackets !\n";
		exit(1);
	}

	char currChar = '\0';
	char nextChar = '\0';
	bool isInvChar = true;
	int len = exp.length();

	for (int index = 0; index < len; index++) {
		currChar = exp[index];
		while (currChar == ' ')
			currChar = exp[++index];

		if (len > index) {
			nextChar = exp[index + 1];
			for (int i = index + 2; len > index&& nextChar == ' '; i++)
				nextChar = exp[i];
		}

		isInvChar = true;
		if (isalnum(currChar) || currChar == '\0') {
			if (isalnum(nextChar) || isOpenBracket(nextChar)) {
				return false;
			}
			isInvChar = false;
		}
		else if (isOperator(currChar)) {
			if (isOperator(nextChar) || isCloseBracket(nextChar) || nextChar == '\0' || index == 0) {
				return false;
			}
			isInvChar = false;
		}
		else if (isCloseBracket(currChar)) {
			if (isalnum(nextChar) || isOpenBracket(nextChar)) {
				return false;
			}
			isInvChar = false;
		}
		else if (isOpenBracket(currChar)) {
			if (isOperator(nextChar) || isCloseBracket(nextChar) || nextChar == '\0') {
				return false;
			}
			isInvChar = false;
		}

		if (isInvChar) {
			cout << "\nInvalid Character found !\n";
			exit(1);
		}

	}
	return true;
}

bool isOpenBracket(char ch) {
	switch (ch) {
	case '(':
	case '{':
	case '[':
		return 1;
	default:
		return 0;
	}
}

bool isCloseBracket(char ch) {
	switch (ch) {
	case ')':
	case '}':
	case ']':
		return 1;
	default:
		return 0;
	}
}

bool isOperator(char ch) {
	switch (ch) {
	case '^':
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;
	default:
		return 0;
	}
}

bool isValidBracket(string str) {
	int index = 0;
	char currChar;
	Stack<char> stack;
	while (currChar = str[index]) {
		if (isOpenBracket(currChar))
			stack.push(currChar);
		else if (isCloseBracket(currChar)) {
			switch (currChar) {
			case ')':
				if (stack.isEmpty() || stack.stackTop() != '(')
					return false;
				stack.pop();
				break;
			case '}':
				if (stack.isEmpty() || stack.stackTop() != '{')
					return false;
				stack.pop();
				break;
			case ']':
				if (stack.isEmpty() || stack.stackTop() != '[')
					return false;
				stack.pop();
				break;
			}
		}
		index++;
	}
	return stack.isEmpty();
}
