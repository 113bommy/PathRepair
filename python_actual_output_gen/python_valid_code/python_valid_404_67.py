a = int(input())
sum = 0
for i in range(a):
    p, q = map(int, input().split())
    if q > p:
        sum += 1

print(sum)