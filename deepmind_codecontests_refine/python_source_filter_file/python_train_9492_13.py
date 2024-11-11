from math import sqrt , gcd

n = int(input())
arr = list(map(int,input().split()))

g = arr[0]
for i in range(1 , n):
    g = gcd(g , arr[i])

ans = 0
for i in range(1 , int(sqrt(g)) + 1 ):
    if g % i == 0 :
        if g // i == i :
            ans +=1
        else:
            ans +=1

print(ans)