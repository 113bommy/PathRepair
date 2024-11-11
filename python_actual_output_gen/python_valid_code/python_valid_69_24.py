n,k=map(int,input().split())
I=list(map(int,input().split()))
for i in range(k,n):
    if I[i-1]<I[i]:
        print("Yes")
    else:
        print("No")
