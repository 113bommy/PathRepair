k = int(input())
k -= 1


c = 9
s = 1
while k >= c * s:
    k -= c * s
    c *= 10
    s += 1
 
n = 10**(s - 1) + k // 2
idx = k % s
print(str(n)[idx])