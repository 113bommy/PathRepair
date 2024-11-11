n = int(input())

a = list(map(int, input().split()))

m = max(a)

counting = True

l = 1

lm = 1

for i in range(n):
    if counting:
        if a[i] == m:
            l += 1
        else:
            counting = False
            lm = max(lm, l)
    else:
        if a[i] == m:
            l = 1
            counting = True

lm = max(lm, l)

print(lm)
