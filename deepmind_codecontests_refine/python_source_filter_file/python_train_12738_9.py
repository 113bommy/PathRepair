n = int(input())
a = []
for i in range(1,n+1):
    a.append(i)
for j in range(len(a)-1):

    a[j],a[j+1] = a[j+1],a[j]
if n == 1:
    print(-1)
else:
    print(*a)