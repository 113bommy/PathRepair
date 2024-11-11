t=int(input())
for j in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    c=0
    for i in range(len(l)-1):
        if(l[i]&l[i-1]):
            c=c+1
    if(c==n-1):
        print(n)
    else:
        print(1)