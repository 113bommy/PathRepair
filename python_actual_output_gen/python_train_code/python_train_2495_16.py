n = int(input())
li = list(map(int, input().split()))
j = 0
while n > 0:
    if j >= n:
        j = 0
    n -= li[j]
    j += 1
print(j)
