s = input().split()
n = int(s[0])
k = int(s[1])

while k > 0:
    if n%10 > 0:
        n -= 1
    else:
        n = int(n/10)
    k -= 1
    
print(k)