N = int(input())

print(sum([x for x in range(1, N) if x % 3 and x % 5]))
