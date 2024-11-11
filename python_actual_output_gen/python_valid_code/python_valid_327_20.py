a, b = map(int, input().split())
count = 0
for i in range(a):
    c = list(map(int, input().split()))
    for j in range(0, len(c)//2 + 2, 2):
        if c[j] != 0 or c[j+1] != 0:
            count += 1
print(count)