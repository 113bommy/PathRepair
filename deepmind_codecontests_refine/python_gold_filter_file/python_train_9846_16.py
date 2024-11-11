input()
citizens = list(map(int, input().split()))
print(abs(sum(citizens) - max(citizens) * len(citizens)))
