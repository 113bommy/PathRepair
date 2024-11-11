n=int(input())
p=[-1]+list(map(int, input().split()))
a=[-1]*(n+1)
o=0
for i in range(1,n+1):
    if p[i]==i:
        o+=1
    elif a[p[i]]== -1 == a[i]:
        o+=1
        a[i]=99
        a[p[i]]=99
print(o)