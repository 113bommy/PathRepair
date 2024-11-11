q, d = map(int, input().split())
p = list(map(int, str(q)))
n = len(p)
max_n = 0
for i in range(n - 1, -1, -1):
    if p[i] != 9:
        found_positive = False
        for j in range(i - 1, -1, -1):
            if p[j] > 0:
                found_positive = True
                idx = j
                break
        if found_positive:
            p[idx] -= 1
            for j in range(i, idx, -1):
                p[j] = 9
        else:
            print(max_n)
            exit()
    temp = int(''.join(map(str, p)))
    if q - temp <= d:
        max_n = temp
print(max_n)
