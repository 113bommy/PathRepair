[n, k] = [int(i) for i in input().split()]
n = str(n)
if list(n).count('0') < k:
    print(len(n) - 1)
    exit(0)
count0 = 0
era = 0
for i in range(len(n)):
    if n[len(n) - 1 - i] == '0':
        count0 += 1
        if count0 == k:
            print(era)
            break
        else:
            era += 1