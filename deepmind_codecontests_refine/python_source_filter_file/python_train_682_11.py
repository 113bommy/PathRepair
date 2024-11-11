def fail():
    print(-1)
    exit()
read = lambda: map(int, input().split())
n = int(input())
a = sorted(read())
b = sorted(read())
for i in range(1, 6):
    if (a.count(i) + b.count(i)) % 2:
        fail()
cnt = 0
while 1:
    flag = False
    for i in range(n):
        if a.count(a[i]) != b.count(a[i]):
            for j in range(n):
                if a.count(b[j]) != b.count(b[j]) and a[i] != b[j]:
                    a[i], b[j] = b[j], a[i]
                    cnt += 1
                    break
            if flag: break
        if flag:
            break
    if not flag:
        break
print(cnt)