n=int(input())
l=[i for i in range(n)]
a=0
for i in range(n):
    l[i]=[int(x) for x in input().split()]
    if (l[i][1]-l[i][0])==2:
        a+=1
print(a)   