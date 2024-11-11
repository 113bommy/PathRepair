test_cases = int(input())

for i in range(test_cases):
    number = int(input())
    remainder = number / 3
    out = number % 3
    
    if not out:
        print(remainder,remainder)
    elif out == 1:
        print(remainder+1,remainder)
    else:
        print(remainder,remainder+1)
