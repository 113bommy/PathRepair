n = int(input())
l = 0
for i in range(1,n):
    if n % i == 0:
        l += 1
print(l)