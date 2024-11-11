import math
n = int(input())
base = 'ROYGBIV'
add = 'BGYOR' 
ans = base

while len(ans) < 150:
    ans += ans[-8:-4][::-1]

print(ans[:n])
