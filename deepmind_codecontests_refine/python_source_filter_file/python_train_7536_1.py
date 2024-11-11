import math 
n = int(input())
l = [int(x) for x in input().split()]
a1 = sum(l)
a2 = n
a3 = 0
temp = 0
for i in range(n):
    temp += l[n-i-1] 
    a3-=(a1-temp)
    a3+=(n-i-1)*(l[n-i-1])

a1 = a1+a3+a3
a4 = math.gcd(a1, a2)
print(a1//a4, a2//a4)

