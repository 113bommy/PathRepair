a = int(input())
k = 0
for i in range(1, a):
    if a % i == 0:
        k += 1
print(k)
