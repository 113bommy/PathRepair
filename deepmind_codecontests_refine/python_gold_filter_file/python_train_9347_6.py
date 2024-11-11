n = int(input())
al = list(map(int, input().split()))
s = sum(al)
acc = 0
res = 10**18
for a in al:
    acc += a
    res = min(res, abs((s-acc)-acc))
print(res)