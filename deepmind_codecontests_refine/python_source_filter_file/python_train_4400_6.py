n=int(input())
a=[int(x) for x in input().split()]
for i in range(n):
    print(a.index(a[i])+1,end=" ")