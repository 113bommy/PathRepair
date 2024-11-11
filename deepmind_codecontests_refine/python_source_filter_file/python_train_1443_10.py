n=int(input())
a=list(map(int,input().split()))
a.sort()
A=2**(n//2)%(10**9+7)
for i in range(n):
 if i+(i-n)%2==a[i]:A=0
print(A)