n, x = [int(j) for j in input().split()]
ref = 1001 * [0]
for j in range(n):
    a, b = sorted([int(j) for j in input().split()])
    for k in range(a, b + 1):
        ref[k] += 1
def check(index):
    if index >= 0 and index < 1001:
        return ref[index] == n
    return False
d = 0
while True:
    if check(x - d) == True or check(x + d) == True:
        break
    d += 1
    if d > n:
        d = -1
        break
print(d)
