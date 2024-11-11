n=int(input())
a=list(map(int,input().split()))
print(min(abs(180-sum(a[l:r])) for l in range(n) for r in range(l,n)))
