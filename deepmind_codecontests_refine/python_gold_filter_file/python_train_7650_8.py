def is_prime(num):
    """Returns True if the number is prime
    else False."""
    if num == 0 or num == 1:
        return False
    for x in range(2, num):
        if num % x == 0:
            return False
    else:
        return True

n = int(input())
p = []
if n == 1: pass
else:
    p = list(filter(is_prime, range(1, n+1)))
add = []
for x in p:
    exp = 2
    while x**exp <= n:
        add.append(x**exp)
        exp += 1
p += add
print (len(p))
print (' '.join(str(x) for x in p))