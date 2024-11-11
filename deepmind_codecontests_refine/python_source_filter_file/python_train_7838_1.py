k = int(input())
months = list(map(int, input().split()[:12]))
months.sort()
flag = 0
j = 11
while k > 0 and j >= 0:
    flag += 1
    k -= months[j]
    j -= 1
if k != 0:
    print(-1)
else:
    print(flag)