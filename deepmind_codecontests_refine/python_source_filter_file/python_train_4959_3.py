from functools import reduce

n = int(input())
arr = list(map(int, input().split()))

def gcd(a, b):
    if a > b: a, b = b, a
    if (b % a == 0): return a
    return gcd(a, b % a)

g = reduce(gcd, arr)
if g != min(arr):
    print(-1)
else:
    ans = []
    for elt in arr:
        ans.append(g)
        ans.append(elt)
    print(len(ans))
    print(" ".join(list(map(str, arr))))