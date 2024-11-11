n = int(input())
n_1 = int(n ** (1/2))
s = 0
 
for i in range(1,n_1):
    if n % i == 0:
        if i < n // i -1:
            s += (n // i) - 1

print(s)