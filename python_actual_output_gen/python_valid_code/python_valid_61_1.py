a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
n = int(input())
x = sum(a)
y = sum(b)

if x // 5 if x % 5 == 0 else x // 5 + 1 + y // 10 if y % 10 == 0 else y // 10 + 1 > n:
    print("NO")
else:
    print("YES")