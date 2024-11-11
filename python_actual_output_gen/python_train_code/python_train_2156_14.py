n = int(input())
l = list(map(int, input().split()))
index = 0
mx = -1
f = True
for i in range(n):
    if mx < l[i]:
        index = i
        mx = l[i]
for i in range(index, n-1):
    if l[i] < l[i+1]:
        f = False
for i in range(index, 1, -1):
    if l[i] < l[i-1]:
        f = False
if not f:
    print("NO")
else:
    print("YES")
