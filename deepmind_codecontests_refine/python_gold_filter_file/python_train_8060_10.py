m,n=map(int,input().split())
l=list(map(int,input().split()))
l.sort(reverse=1)
print(l[n-1])
