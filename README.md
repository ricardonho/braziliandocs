# braziliandocs
A simple command line tool to calculate verifying digits from common identity documents in Brazil and some feature tools to generate all possible documents

# build instructions
Just run *make* or gcc -digits.c utils.c main.c -o docs

# how to use it

docs cpf 012345678 --masked "###.###.###-##"

docs cnpj 012345670001 --masked "##.###.###/####-##"
