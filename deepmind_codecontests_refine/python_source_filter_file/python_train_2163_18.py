# C

N=int(input())
A=list(map(int,input().split()))
p=10**9+7

sumA = sum(A)

sumA2 = sum([a**2 for a in A])

print(int((sumA**2-sumA2)/2)%p)