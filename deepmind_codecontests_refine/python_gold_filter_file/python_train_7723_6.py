t=int(input())
for i in range(0,t):
    n=int(input())
    a=[int(x) for x in input().split()]
    a.sort()
    mx=0
    for j in range(n-1,-1,-1):
        if a[j]>mx:
            mx+=1
    print(mx)