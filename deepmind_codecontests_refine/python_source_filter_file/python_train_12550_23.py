l = list(input().split())
n = int(l[0])
c = int(l[1])
l = list(input().split())
l = [int(i) for i in l]
length = 0
for i in range(n - 1):
    if l[i + 1] - l[i] <= c:
        length += 1
    else:
        length = 1
print(length)