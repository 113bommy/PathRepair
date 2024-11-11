n = int(input())
x = []
y = []
for i in range(n):
    p,q = map(int,input().split())
    x += [p]
    y += [q]
l = max(x)-min(x)
w = max(y)-min(y)
print(l*w)