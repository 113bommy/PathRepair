n = int(input())
l = [*map(int, input().split())]
print(1 / sum(1 / e for e in l))