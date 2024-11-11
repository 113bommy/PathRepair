n = int(input())
cnt = 1
for i in range(2, n):
    if (n-i)%i == 0:
        cnt += 1
print(cnt)