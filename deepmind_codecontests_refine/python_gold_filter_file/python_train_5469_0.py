from fractions import gcd

n = int(input())
l = list(map(int,input().split(' ')))
k = 0
i = 1
while i < n+k :
    if gcd(l[i],l[i-1]) != 1:
        #print(l[i-1],l[i])
        k += 1
        l = l[:i]+[1]+l[i:]
    i += 1

print(k)
print(*l)
