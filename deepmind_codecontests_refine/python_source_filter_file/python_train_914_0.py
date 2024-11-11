n = int(input())
h = list(map(int,input().split()))
c = 1
for i in range(n):
    if h[i] >= max(h[0:i]):
        c += 1
print(c)