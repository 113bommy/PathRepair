from math import gcd
n = int(input())
l = list(map(int,input().split()))
cnt = 0
g = 0
for i in range(n):
    g = gcd(g,i)

z = max(l)//g - n
if z%2!=0:
    print('Alice')
else:
    print('Bob')





