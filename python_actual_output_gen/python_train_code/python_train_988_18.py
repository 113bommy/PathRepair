n,k=map(int,input().split())
o,D=0,[]
a=[int(z)for z in input().split()]+[-1]*2
for i in range(n+1):
    if a[i]==a[i+1]:
        D+=[o]
        o=0
    else:
        o+=1
print(max(D)+1)