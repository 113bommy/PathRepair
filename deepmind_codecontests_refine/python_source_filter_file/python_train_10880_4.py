from sys import stdin
input = stdin.readline

n = int(input())
if n % 2 == 1:
    print(1)
else:
    print(n // 4 - (n % 4 == 0))