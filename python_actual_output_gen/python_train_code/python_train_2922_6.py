n=int(input())
k=0
for i in range(n):
    s,d=list(map(int,input().split()))
    p=k-s
    k=s+d*(p//d+1*(p % d !=0 or p==0))*(p>=0)
print(k)

