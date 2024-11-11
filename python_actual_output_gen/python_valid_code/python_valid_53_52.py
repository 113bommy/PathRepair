k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())

punched = [False] * d
for i in range(d):
    if ((i-1) % k) == 0:
        punched[i] = True
    if ((i-1) % l) == 0:
        punched[i] = True
    if ((i-1) % m) == 0:
        punched[i] = True
    if ((i-1) % n) == 0:
        punched[i] = True
sum = 0
for r in range(d):
    if punched[r-1] == True:
        sum += 1
print(sum)