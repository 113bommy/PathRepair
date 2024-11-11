k = int(input())
L = int(input())
m = int(input())
n = int(input())
d = int(input())
counter = 0
for i in range(d):
    if i % k == 0 or i % L == 0 or i % m == 0 or i % n == 0:
        counter += 1
print(counter)