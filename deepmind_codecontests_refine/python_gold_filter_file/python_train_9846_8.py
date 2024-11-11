mx=0
sm=0
n=int(input())
s=input().split(" ")
for i in range(n):
    k=int(s[i])
    mx=max(k,mx)
    sm+=k
bonus=mx*n-sm
print(bonus)