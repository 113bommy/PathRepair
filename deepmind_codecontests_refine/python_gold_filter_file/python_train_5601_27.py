n = int(input())
a = map(int, input().split())

print(1 / sum(1 / x for x in a))