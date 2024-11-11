def is_prime(n):
    if n == 1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n % i == 0:
            return False
    return True
p = []
for i in range(1,11111):
    n = 5*i + 1
    if is_prime(n):
        p.append(str(n))
N = int(input())
a = p[:N]
print(' '.join(p))