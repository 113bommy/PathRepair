t=int(input())
for i in range (t):
    n=int(input())
    k=list(map(int,input().split()))
    for j in range (0,n,2):
        a=k[j]
        b=k[j+1]
        print(b*(-1),a*(-1),end=" ")
    print()
