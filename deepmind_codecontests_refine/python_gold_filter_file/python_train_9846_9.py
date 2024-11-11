input()
k = list(map(int, input().split()))
ret = 0

for i in k:
    ret += max(k) - i

print(ret)
