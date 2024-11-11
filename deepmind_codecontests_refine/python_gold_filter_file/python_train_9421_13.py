n = int(input())
k = []
a,b = [],[]
for i in range(n**2):
    x, y = map(int,input().split())
    if x not in a and y not in b:
        k.append(i+1)
        a.append(x)
        b.append(y)
print(*k)