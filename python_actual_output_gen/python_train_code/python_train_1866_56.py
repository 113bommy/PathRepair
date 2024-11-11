n = int(input())
m = int(input())
base = 1
for i in range (n):
    base*=2
    if base >=m:
        break

print(m%base)