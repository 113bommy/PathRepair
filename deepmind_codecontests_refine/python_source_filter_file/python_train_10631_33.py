n=int(input())
a=list(map(int,input().split()))
print(n+1)
print(1,n,1000000)
for i in range(n):
    print(2,i+1,a[i]+1000000-i)