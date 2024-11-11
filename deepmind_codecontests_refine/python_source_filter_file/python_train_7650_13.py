n = int(input())

def prime(n):
    i = 3
    if n == 2 :
        return True
    if n % 2 == 0 :
        return False
    while i*i <= n :
        if n % i == 0 :
            return False
        i += 2
    return True

pr = [i for i in range(2,n) if prime(i)]
prm = []
for p in pr :
    x = p
    prm.append(x)
    while True:
        #print(x)
        x *= p
        if x > n :
            break
        prm.append(x)

print(len(prm))
print(*prm)
