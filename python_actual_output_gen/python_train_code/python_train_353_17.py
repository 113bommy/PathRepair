a,b = map(int,input().split())
c,d = map(int,input().split())
res = -1
for i in range(10000):
    if (b+a*i-d) % c == 0 and b+a*i-d > 0:
        res = b+a*i
        break
print(res)