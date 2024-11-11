n = int(input())
h = 0
for i in range(n):
    p,q = map(int,input().split())
    if (q-p)>2:
        h = h+1
print(h)