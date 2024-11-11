n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
d = {}
for j in range(m):
    for i in range(n):
        if b[j]%a[i]==0:
            k = b[j]//a[i]
            d[k]=d.get(k,0)+1
#print(d)
sor = sorted(d.items(),key=lambda x: x[0],reverse=True)
print(sor[0][1])
#print(sor)