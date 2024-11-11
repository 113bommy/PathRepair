n = int(input())
l = list(map(int, input().split()))
amz = 0
mx, mn = 0, 0
for i in range(1, len(l)):
    if l[i] > l[mx]:
        amz += 1
        mx = i
    if l[i] < l[mn]:
        amz += 1
        mn = i
print(amz)
