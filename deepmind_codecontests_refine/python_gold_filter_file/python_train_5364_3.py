n, p = map(int, input().split())
x = int(''.join('10'[input()=='half'] for _ in range(n))[::-1], 2)
k = 0

while x:
    k += x/2
    x //= 2

print(int(k*p))