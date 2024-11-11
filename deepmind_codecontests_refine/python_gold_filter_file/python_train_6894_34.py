t=int(input())
for i in range(t):
    n,m=[int(x) for x in input().split()]
    if(n%m==0):
        print("YES")
    else:
        print("NO")