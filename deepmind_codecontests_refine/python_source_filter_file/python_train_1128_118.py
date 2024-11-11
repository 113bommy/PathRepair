n = int(input())
a = list(map(lambda x:int(x)//400, input().split()))

r = len(set(range(8)) & set(a))
cnt = 0
for i in a:
    if i >= 8: cnt += 1

x, y = r, r+cnt
print(x, y)