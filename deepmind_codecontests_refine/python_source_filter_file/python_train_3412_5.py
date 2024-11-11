n = int(input())
s = 7
for i in range(1, n):
    if s%n == 0:
        print(i)
        exit()
    s = (s*10 + 7) % n
print(-1)
