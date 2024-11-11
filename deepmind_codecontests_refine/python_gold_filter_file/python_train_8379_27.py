n = int(input()) 
a = 1
b  = 1
mod = 1e9+7

for i in range(3*n):
    a = (a*3) % mod

for i in range(n):
    b = (b*7) % mod

print(int((a-b + mod) % mod))