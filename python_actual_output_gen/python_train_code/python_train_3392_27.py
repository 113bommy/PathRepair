n = int(input())

welfare = map(int, input().split())

equal = max(welfare)

spend = sum(equal - w for w in welfare)

print(spend)
