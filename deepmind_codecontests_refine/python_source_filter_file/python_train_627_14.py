a,b,c = map(i, input().split())
ret = 0
for i in range(a,b+1):
    if c % i == 0:
        ret += 1
print(ret)
