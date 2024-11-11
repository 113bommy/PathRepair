def mod(b, q): #computes b^k mod q for large k
    for i in range(6):
        b = (b * b) % q
    return b

n = int(input())
s = ''
for i in range(n - 1):
    p, q, b = list(map(int, input().split()))
    if (p * mod(b, q))%q: #checks if p * b^k is not divisible by q for large k
        s += 'Infinite\n'
    else:
        s += 'Fininte\n'
p, q, b = list(map(int, input().split()))
if (p * mod(b, q))%q: #checks if p * b^k is not divisible by q for large k
    s += 'Infinite'
else:
    s += 'Fininte'
print(s)