from sys import stdin
from collections import defaultdict

for _ in range(int(stdin.readline())):
    n, m, k = map(int, stdin.readline().split())
    if n%2 == 0:
        if k%2 == 0 and k <= n * (m//2):
            print("Yes")
        else:
            print("No")
    else:
        if k > (m//2) and (k - (m//2)) % 2 == 0:
            print("Yes")
        else:
            print("No")

