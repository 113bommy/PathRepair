n = int(input())
a = list(map(int, input().split()))

one = a.count(1)
two = a.count(2)
th = a.count(3)

print(min(one, two, th))
