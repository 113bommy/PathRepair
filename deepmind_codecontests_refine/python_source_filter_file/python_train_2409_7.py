n = int(input())
a = list(map(int, input().split()))
m = max(a)
a.append(-1)
i = 0
mm = 0
while i < n:
    if (a[i] == m):
        j = i
        while a[i] == m:
            i += 1
        if i - j> mm:
            mm = i - j + 1
    i+=1
print(mm)