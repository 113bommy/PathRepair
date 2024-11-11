def gcd(a, b) :
    if a == 0 :
        return b
    return gcd(b%a, a)

n = int(input())

divisors = []

for i in range(2, int(n**0.5) + 1) :
    if n%i == 0 :
        divisors.append(i)
        divisors.append(int(n/i))

if len(divisors) == 0 :
    print(n)
elif len(divisors) == 1 :
    print(divisors[0])
else :
    g = divisors[0]
    for i in range(len(divisors)) :
        g = gcd(g, divisors[i])
    
    print(g)