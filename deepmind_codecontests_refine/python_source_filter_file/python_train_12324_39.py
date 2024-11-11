def execute_bit(test_cases):
    X = 0
    for eachStatement in range(1, (test_cases+1)):
        statement = input()
        instruction = statement.split('X')
        for each in instruction:
            if each == '++':
                X += 1
            elif each == '--':
                X -= 1
    print(X)

def main():
    test_cases = int(input())
    if test_cases >= 1 and test_cases <= 100:
        execute_bit(test_cases)

if __name__ == '__main__':
    main()