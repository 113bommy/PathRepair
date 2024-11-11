t = int(input())
for i in range(t):
    n = int(input())
    m = 2*(2**(n//2-1) -1) + 2**n
    k = (2 * ((2**n) -1)) - m
    j = m-k
print(j)