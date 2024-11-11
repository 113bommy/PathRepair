n,m=map(int,input().split())
seq=[int(i) for i in input().split()][:n]
f=[int(i) for i in input().split()][:m]
a=[]
for i in range(n):
    for j in range(m):
        if(seq[i]==f[j]):
            a.append(seq[i])

for i in range(len(a)):
    print(a[i],end=' ')