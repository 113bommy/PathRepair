n=int(input())
h=list(map(int,input().split()))
c=sum(max(h[:i])<=h[i] for i in range(1,n))+1
print(c)