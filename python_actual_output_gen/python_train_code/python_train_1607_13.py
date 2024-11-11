a = int(input())
num = 0
for x in range(a):
    n, m, a = map(int, input().split())
    if n and m == 1 or n and m == 1 or m and a == 1 or n and m and a == 1:
        num += 1
print(num)