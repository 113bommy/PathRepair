n = int(input())
temp = list(map(int, input().split()))
max_len = 1
cnt = 1
for i in range(1, n):
    if temp[i] >= temp[i-1]:
        cnt += 1
    else:
        cnt = 1
    if cnt > max_len:
        max_len = cnt
print(max_len)
