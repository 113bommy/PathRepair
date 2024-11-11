n, a, b = map(int, input().split())
m = list(map(int, input().split()))
i = 0
j = len(m) - 1
count = 0
ans = 0
while not (i == j) and not (i == j - 1) and i >= 0 and j >= 0 :
    if m[i] != 2 or m[j] != 2:
        if m[i] == 2 and m[j] == 0:
            count += a
        elif m[i] == 2 and m[j] == 1:
            count += b
        elif m[j] == 2 and m[i] == 0:
            count += a
        elif m[j] == 2 and m[i] == 1:
            count += b
        elif m[i] != m[j]:
            ans = -1
            i = -100
            j = -100        
    else:
        count += 2 * min(a, b)
    i += 1
    j -= 1
if i == j and m[i] == 2:
    count += min(a, b)
if ans == -1:
    print(ans)
else:
    print(count)