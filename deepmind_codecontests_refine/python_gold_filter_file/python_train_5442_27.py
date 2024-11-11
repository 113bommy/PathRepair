import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    digits =[int(c)%2 for c in list(input())[:-1]]
    if len(digits)%2 == 1:
        if sum(digits[::2]) > 0:
            print(1)
        else:
            print(2)
    else:
        if sum(digits[1::2]) < len(digits[1::2]):
            print(2)
        else:
            print(1)
