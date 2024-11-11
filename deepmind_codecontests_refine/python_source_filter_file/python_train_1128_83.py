n = int(input())
a = map(int, input().split())
l = [0 for i in range(9)]

for i in a:
    if i // 400 >= 8:
        l[8] += 1
    else:
        l[i // 400] = 1
print(sum(l[:8]), sum(l))
