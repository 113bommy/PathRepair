n = int(input())

prevsp = []
newsp = []
am = 0

for i in range(n):
    prevsp.append(input())

for i in range(n):
    newsp.append(input())

for i in range(n):
    try:
        t = prevsp.index(newsp[i])
        if(t != -1):
            prevsp.pop(t)
            am += 1
    except Exception:
        continue

print(n-am)


