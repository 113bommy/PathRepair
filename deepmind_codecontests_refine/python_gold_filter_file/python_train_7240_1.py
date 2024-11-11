n=int(input())
k=list(map(int,input().split()))
i=1
while i<n:
    print(k[i]+k[i-1],'',end="")
    i=i+1
print(k[n-1])