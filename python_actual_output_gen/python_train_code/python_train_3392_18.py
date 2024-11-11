input()
t = map(int, input().split())
print(sum(map(lambda x: max(t) - x, t)))
