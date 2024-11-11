import bisect
n=int(input())
l=[int(x) for x in input().split()]
ind={0:-1}
s=0
c=0
j=0
for i in range(n):
    s+=l[i]
    if s not in ind:
        ind[s]=i
        c+=i-j
    elif s in ind:
        j=max(j,ind[s]+1)
        c+=i-j
        ind[s]=i
print(c)
