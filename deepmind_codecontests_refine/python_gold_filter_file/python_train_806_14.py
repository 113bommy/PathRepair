n=int(input())
l=[int(i) for i in input().split()]
c=0
for i in range(1,n):
    c+=max(l[i-1]-l[i],0)
    l[i]+=max(l[i-1]-l[i],0)
print(c)