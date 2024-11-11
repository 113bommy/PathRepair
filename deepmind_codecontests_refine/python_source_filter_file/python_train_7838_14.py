R = lambda:list(map(int,input().split()))
k = int(input())
a = R()
a.sort(reverse=True)
z = 0
i = 0
while (z < k and i < 12):
    z += a[i]
    i += 1
if i == 12:
    print(-1)
else:
    print(i)