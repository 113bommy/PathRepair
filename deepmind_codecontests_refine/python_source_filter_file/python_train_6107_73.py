n = [int(i) for i in input()]
t = 0
for i in range(len(n) - 1):
    if n[i] == n[i + 1]:
        t += 1
        if t >= 7:
            print("YES")
            break
    else:
        t = 0
else:
    print("NO")

