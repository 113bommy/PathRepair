z = int(input())
g = 0
n = []
for i in range(z):
    x,c,v,b = list(map(int,input().split()))
    n.append(x+c+v+b)
for j in range(len(n)):
    if n[j] > n[2]:
        g += 1
if g > 0:
    print(g+1)
else:
    print(1)