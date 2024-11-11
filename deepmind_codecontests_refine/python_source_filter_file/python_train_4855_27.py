def isBeau(x):
    x = bin(x)[2:]
    if len(x) % 2 == 0:
        return False
    else:
        if x[:len(x) // 2 + 1] != '1' * (len(x) // 2 + 1):
            return False
        if x[len(x) // 2 + 1:] != '0' * (len(x) // 2):
            return False
    return True

cur = 1
n = int(input())
for i in range(2, round(n ** (1/2)) + 1):
    if n % i == 0 and isBeau(i):
        cur = max(cur, i)
    if n % i == 0 and isBeau(n // i):
        cur = max(cur, n // i)
print(cur)        
        