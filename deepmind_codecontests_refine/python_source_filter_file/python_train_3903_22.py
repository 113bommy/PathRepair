n = int(input())
length = 0
val = 0
mul = 1
while n > 0:
    if n%10 == 7:
        val += 1*mul
    else:
        val += 0*mul 
    mul <<= 1
    length += 1
    n //= 10
ans = val+1
mul = 1
while length > 1:
    ans += 1 << mul
    mul <<= 1
    length -= 1
print(ans)