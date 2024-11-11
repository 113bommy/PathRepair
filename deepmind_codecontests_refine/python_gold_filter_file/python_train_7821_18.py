# 5
# 3 2 5 4 10

n = int(input())
l = list(map(int, input().split()))
total = 0
temp = 2000000000
for i in reversed(range(n)):
    if l[i] < temp and temp>0:
        temp = l[i]
        total += temp
    elif l[i] >= temp and temp>0:
        temp = temp-1
        total += temp
print(str(total))