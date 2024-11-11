n = int(input())
x = 0
for i in range(n):
    temp = tuple(map(lambda x: int(x), input().split(" ")))
    if sum(temp) > x:
        x = sum(temp)
        r = temp
print(sum(temp))