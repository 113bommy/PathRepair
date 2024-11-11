from sys import stdin
input = stdin.readline
n, k = map(int, input().split())
l = list(map(int, input().split()))
skills = 0
remain = 0
for i in range(n):
    skills += l[i] // 10
    a = round(l[i], -1)
    if a < l[i]:
        a += 10
    if a < 100:
        remain += (100-a)//10
    if a >= 100:
        l[i] = 0
        continue
    b = a - l[i]
    l[i] = b
spent = 0
l.sort()

for i in range(len(l)):
    if spent + l[i] <= k and l[i] != 0:
        skills += 1
        spent += l[i]


skills += min(remain, (k - spent) // 10)
print(skills)
