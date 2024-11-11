n,m = map(int,input().split())
mas = []
k = 0
for i in range(n):
    a = [int(s) for s in input().split()]
    mas.append(a[0]-a[1])
    k+=a[0]
mas = sorted(mas,reverse=True)
i = 0
while k>m and i<n:
    k-=mas[i]
    i+=1
if i==n:
    print(-1)
    exit()
print(i)