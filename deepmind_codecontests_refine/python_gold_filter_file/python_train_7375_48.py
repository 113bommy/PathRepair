n=int(input())
a=list(map(int,input().split()))
a=sorted(a,reverse=1)
print(sum(a[1:n*2:2]))