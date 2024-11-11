orda = ord('a')
ord0 = ord('z')-orda+1

n = int(input())
s = input()
t = input()
sv = [ord(si)-orda for si in s]
tv = [ord(ti)-orda for ti in t]

medv = [ord(si)-orda for si in s]
for i in range(n-1, -1, -1):
    medv[i] += tv[i]
    if i > 0 and medv[i] > ord0:
        medv[i] -= ord0
        medv[i-1] += 1
for i in range(n):
    if i < n-1 and medv[i]%2 == 1:
        medv[i+1] += ord0
    medv[i] //= 2
ans = ''.join([chr(medvi+orda) for medvi in medv])
print(ans)