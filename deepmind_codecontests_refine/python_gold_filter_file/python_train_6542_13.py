n, p = map(int, input().split())
a = [int(i)&1 for i in input().split()]
odd = sum(a)
ans = 0
if odd:
    ans = 2**(n-1)
else:
    ans = 2**n*(1-p)

print(ans)