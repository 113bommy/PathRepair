
n, k = [int(x) for x in input().split()]

l = [int(x) for x in input().split()]

scr = []
s = set()
i = -1

for msg in l:
    if msg not in s:
        s.add(msg)
        scr.append(msg)
        if len(scr) > k:
            s -= {scr[i]}
            i += 1


print(len(scr) - i)
print(*reversed(scr[i:]))
