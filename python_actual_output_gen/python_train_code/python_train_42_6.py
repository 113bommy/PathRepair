n = int(input())
data = list(map(int, input().split()))
sg1 = 0
sg2 = 0
for i in data:
    sg2 += i
maxi = max(data)
for i in range(maxi, 101):
    for k in data:
        sg1 += (i - k)
    if sg1 > sg2:
        print(i)
        break
    sg1 = 0
