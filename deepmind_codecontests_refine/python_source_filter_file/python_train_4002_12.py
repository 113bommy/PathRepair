def main():
    OK_MESSAGE = 'Correct'
    ERROR_MESSAGE = 'Too weak'
    BIG_ALPHABET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    ALPHABET = 'abcdefghijklmnopqrstuvwxyz'
    LEN_ABC = 26
    NUMBERS = '1234567890'
    NUMBER_NUMBERS = 10
    MIN_LENGTH = 5
    flag = True
    password = input()
    errors = 0
    if len(password) < 5:
        flag = False
    for i in range(LEN_ABC):
        if not BIG_ALPHABET[i] in password:
            errors += 1
    if errors == 26:
        flag = False
    errors = 0
    for i in range(LEN_ABC):
        if not ALPHABET[i] in password:
            errors += 1
    if errors == 26:
        flag = False
    errors = 0
    for i in range(NUMBER_NUMBERS):
        if not NUMBERS[i] in password:
            errors += 1
    if errors == 26:
        flag = False
    if flag:
        print(OK_MESSAGE)
    else:
        print(ERROR_MESSAGE)

main()