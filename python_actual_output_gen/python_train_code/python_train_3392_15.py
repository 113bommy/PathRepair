input()
citizens = list(map(int, input().split()))
print(abs(sum(citizens) - citizens[-1] * len(citizens)))
