n=int(input())
h=list(map(int,input().split()))
c=sum(max(h[:i])<=h[i] for i in range(n))
print(c)