n = int(input())
a = []
k = []
for i in range(n**2):
    x, y = map(int,input().split())
    if x not in a and y not in a:
        k.append(i+1)
        a.append(x)
        a.append(y)
print(*k)