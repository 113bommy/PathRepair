n=int(input())
l=[int(x) for x in input().split()]
l1=[int(x) for x in range(n)]
for i in range(n):
    l1[l[i]-1]=i+1
print(l1)

