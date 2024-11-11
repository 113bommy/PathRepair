t=int(input())
for i in range(t):
    n=int(input())
    l=[int(i) for i in input().split()]
    l=[0]+l
    if all(l[i]==l[i+1] for i in range(1,n-1)):
        print(n)
    else:
        print(1)