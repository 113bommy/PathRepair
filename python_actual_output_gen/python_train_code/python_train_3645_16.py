a,b = map(int,input().split())
res = 0
while a < b:
    res += 1
    a *= 2
print(res)