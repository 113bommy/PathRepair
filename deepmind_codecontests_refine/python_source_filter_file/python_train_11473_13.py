from math import gcd
for _ in range(int(input())):
    print("infinite" if gcd(*map(int, input().split())) <= 1 else "finite")