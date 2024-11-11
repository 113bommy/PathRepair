N,*a = map(int,open(0).read().split())
cnt = 0
for i in a[1::2]:
    if i % 2 != 0:
        cnt += 1
print(cnt) 