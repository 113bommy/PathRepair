IL = lambda: list(map(int, input().split()))
IS = lambda: input().split()
I = lambda: int(input())
S = lambda: input()

n = I()
primes = [True for i in range(n+2)]
for i in range(2, n+2):
    if primes[i]:
        for j in range(i*2, n+2, i):
            primes[j] = False

print(1 if n<3 else 2)
print(" ".join(["1" if i else "2" for i in primes[2:]]))