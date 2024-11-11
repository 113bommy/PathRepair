n = int(input())
table = list(map(int, input().split()))

sum = 0
for i in table:
    sum += i
avg = sum/(n/2)
if avg < (n/2 + 0.5):
    pos = 1
else:
    pos = 2

sm = 0
for i in table:
    sm += abs(i - pos)
    pos += 2

print(sm)