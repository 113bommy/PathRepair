n = int(input())
x = list(map(int, input().split()))
x.sort()
while x[-1] != x[-2]:
    x[-1] = x[-1] - x[-2]
    x.sort()
print(sum(x))
