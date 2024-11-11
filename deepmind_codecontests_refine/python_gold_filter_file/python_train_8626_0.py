import sys
f = sys.stdin

def create_prime(n):
    prime = [1] * (n + 1)
    prime[:2] = [0, 0]
    for i in range(len(prime)):
        if prime[i]:
            for j in range(2 * i, len(prime), i):
                prime[j] = 0
    return prime

sieve = create_prime(50000)

prime = []
for i in range(25001):
    if sieve[i]:
        prime.append(i)

while True:
    n = int(f.readline())
    if n == 0:
        break
    cnt = 0
    temp = n // 2
    for i in prime:
        if i > temp:
            break
        if sieve[n - i]:
            cnt += 1
    print(cnt)