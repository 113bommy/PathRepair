n=int(input())
print(n+1)
print(1,n,10**5)
l=list(map(int,input().split()))
l=[l[i]+100000 for i in range(n)]
for i in range(n-1):
    print(2,i+1,l[i]-i)