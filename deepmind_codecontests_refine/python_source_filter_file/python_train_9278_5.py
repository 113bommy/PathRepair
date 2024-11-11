import math


def ii():
    return int(input())


def mi():
    return map(int, input().split())


def li():
    return list(mi())


n = ii()
root =int(pow(n,0.5))
num = root*root
if n==num:
    ans = 2*root
else:
    ans = root + (1 if n-num <=root else 2)

print(ans)
