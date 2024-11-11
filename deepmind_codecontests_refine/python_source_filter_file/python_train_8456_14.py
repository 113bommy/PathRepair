""" 1343A - Candies """
try:
    for _ in range(int(input())):
        n = int(input())
        x, k = 1, 1

        for i in range(2, 29):
            if n % ((2 ** i) - 1) == 0:
                x = n // ((2 ** i) - 1)
                if x != 0:
                    print(x)
                    break 
except EOFError as e:
    pass