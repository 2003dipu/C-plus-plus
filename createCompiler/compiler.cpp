#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Token
{
public:
    enum Type
    {
        IDENTIFIER,
        NUMBER,
        OPERATOR,
        KEYWORD,
        PUNCTUATOR,
        END_OF_FILE
    };

    Type type;
    string value;

    Token(Type type, string value)
        : type(type), value(value) {}

    // Default constructor
  Token() : type(IDENTIFIER), value("") {}

 
};

class Lexer
{
public:
    Lexer(string source)
        : source(source), position(0) {}

    Token nextToken()
    {
        while (position < source.length())
        {
            char c = source[position];

            if (isspace(c))
            {
                position++;
                continue;
            }

            if (isalpha(c))
            {
                // Identifier or Keyword
                string identifier;
                while (isalnum(source[position]))
                {
                    identifier += source[position];
                    position++;
                }

                if (identifier == "int" || identifier == "return")
                {
                    return Token(Token::KEYWORD, identifier);
                }
                return Token(Token::IDENTIFIER, identifier);
            }

            if (isdigit(c))
            {
                // Number
                string number;
                while (isdigit(source[position]))
                {
                    number += source[position];
                    position++;
                }

                return Token(Token::NUMBER, number);
            }

            if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                // Operator
                return Token(Token::OPERATOR, string(1, c));
            }

            if (c == '{' || c == '}' || c == '(' || c == ')' || c == ';')
            {
                // Punctuator
                return Token(Token::PUNCTUATOR, string(1, c));
            }

            // Handle other cases as needed.

            // If none of the above, it's an invalid character.
            position++;
        }

        // End of file.
        return Token(Token::END_OF_FILE, "");
    }

private:
    string source;
    size_t position;
};

int main()
{
    Lexer lexer("int main() { return 0; }");

    vector<Token> tokens;
    Token token;
    while ((token = lexer.nextToken()).type != Token::END_OF_FILE)
    {
        tokens.push_back(token);
    }

    for (const Token& token : tokens) {
    cout << token.type << ": " << token.value << endl;
}


    return 0;
}
// this compiler isn't complete. It doesn't work