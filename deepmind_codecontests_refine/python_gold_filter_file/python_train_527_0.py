n, k = [int(i) for i in input().split()]

s = list(set(list(input())))

s.sort()

if len(s) < k:
    print('-1')
else:
    ans =  0
    prev = s[0]
    j = 0
    i = 0
    while j < k and i < len(s):
        if ord(s[i]) == ord(prev) + 1:
            i += 1
            continue
        ans += ord(s[i]) - ord('a') + 1
        j += 1
        prev = s[i]
        i += 1
    if j < k:
        print('-1')
    else:
        print(ans)
