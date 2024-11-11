import math
n = int(input()); d = {}
def is_prime(v):
    for t in range(2, int(math.sqrt(v))+1):
        if  not v%t:
            return t
    return 0
a = []; i = 1;
for t in range(2, n+1):
    if not t%2:
        a.append(1)
    else:
        
        s = is_prime(t)
        if s:
            a.append(s)
            d[t] = d[s]
        else:
            i+=1
            d[t] = i
            a.append(i)
print(" ".join(map(str, a)))
