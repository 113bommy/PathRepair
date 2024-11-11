n=int(input())
a=list(map(int,input().split()))
a.sort(reverse=1)
print(sum(a[n:n*2]))