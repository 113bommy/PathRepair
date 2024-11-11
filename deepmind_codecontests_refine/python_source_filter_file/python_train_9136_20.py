N = int(input())
A = list(map(int, input().split()))

xor = 0
for a in A[2:]:
    xor ^= a

n = A[0] + A[1] - xor
if n < 0 or n%2:
    print(-1)
    quit()

n //= 2
a = b = 0
digit = [1]
d = []
count = 0    
while n or xor:
    n0 = n & 1; xor0 = xor & 1
    if n0:
        if xor0:
            print(-1)
            quit()
        else:
            a += digit[-1]
            b += digit[-1]
    else:
        if xor0:
            b += digit[-1]
            d.append(count)

    digit.append(digit[-1] * 2)
    count += 1
    n >>= 1; xor >>= 1

if a >= A[0]:
    print(-1)
    quit()

while d:
    c = d.pop()
    if a + digit[c] < A[0]:
        a += digit[c]; b -= digit[c]

if a:
    print(A[0] - a)
else:
    print(-1)