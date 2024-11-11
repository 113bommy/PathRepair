n = int(input())
a = list(map(lambda x: int(x)//400, input().split()))

cnt = 0
for i in a:
    if i >= 8:
        cnt += 1
c = len(set(a)) - (1 if cnt != 0 else 0)

print(max(1, c), c+cnt)
