n = int(input())

cs = list(map(int, input().split()))

a = cs[0]
z = cs[-1]
for i in range(n):
    if a != cs[-i] or z != cs[i]:
        print(n - i - 1)
        break
