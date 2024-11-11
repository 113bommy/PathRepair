n = int(input())
a = list(map(int, input().split()))

print(min(sum(map(lambda x: (x - i) * (x - i), a)) for i in range(101)))