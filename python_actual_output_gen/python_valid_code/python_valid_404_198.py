num = int(input())
count = 0
while num != 0:
    p, q = map(int, input().split())
    if p < q:
        count += 1
    num -= 1
print(count)