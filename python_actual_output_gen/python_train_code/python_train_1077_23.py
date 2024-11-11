n=int(input())
w=list(map(int,input().split()))

a=float('inf')
for i in range(1,n-1):
      a=min(abs(sum(w[:i])-sum(w[i:])),a)
print(a)
