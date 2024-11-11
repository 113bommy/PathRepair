n = int(input())
ai = list(map(int,input().split()))
ti = 0
mini = 10**7
for t in range(1,101):
    num = 0
    for i in ai:
        num += max(abs(i - t) - 1,0)
    if num < mini:
        ti = t
        mini = num
print(ti,mini)
