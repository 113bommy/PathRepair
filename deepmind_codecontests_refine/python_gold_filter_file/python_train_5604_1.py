n = int(input())
MX = 55555
is_prime = [True]*MX
is_prime[0] = False
is_prime[1] = False
for i in range(2, MX):
    if not is_prime[i]:
        continue
    for j in range(2*i, MX, i):
        is_prime[j] = False
ans = [i for i, j in enumerate(is_prime) if j and i%5==1]
print(*ans[:n])