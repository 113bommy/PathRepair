n = int(input())

welfare = list(map(int, input().split()))

equal = max(welfare)

spend = sum(equal - w for w in welfare)

print(spend)
