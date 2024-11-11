d, k, a, b, t = [int(x) for x in input().split()]
N = d // k
p = d % k

if (N == 0): T = d * a
if (N == 1):
    if (p * b < t + p * a):
        T = p * b + k * a
    else:
        T = t + p * a + k * a
        
if (N > 1):
    if (b * k < t + a * k):
        T = k * a + (d - k) * b
    else:
        if (b * p < t + b * p):
            T = (N * k) * a + (N - 1) * t + p * b
        else:
            T = (N * k) * a + N * t + p * a
            
print(T)
    