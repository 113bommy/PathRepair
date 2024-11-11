a, b, c = map(int, input().split())
print(len([ x for x in range(a, b) if c % x == 0]))