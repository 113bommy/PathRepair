from sys import stdin, stdout
input, print = stdin.readline, stdout.write
from math import *


def main():
    for _ in range(int(input())):
        k = list(input())
        n = len(k)
        ans = 100
        for i in range(100):
            a = str(2 ** i)
            now = 0
            s = len(a)
            for r in range(n):
                if k[r] == a[now]:
                    now += 1
                if now == s:
                    break
            if ans > s - now + n - now:
                ans = s - now + n - now
        print(str(ans - 1) + '\n')








main()