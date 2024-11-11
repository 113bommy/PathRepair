n = int(input())
a = [int(i) for i in input().split()]

maxleft = 0
while a[maxleft] == 1:
    maxleft += 1

maxright = 0
while a[n -maxright-1] == 1:
    maxright += 1

i = 0
prev = -1
maxmid = 0

while i < n:
    if a[i] == 0 and prev != -1:
        if i - prev > maxmid:
            maxmid = i - prev
            prev = -1
    if a[i] == 1 and prev == -1:
        prev = i
    i += 1

print(max(maxleft+maxright, maxmid))