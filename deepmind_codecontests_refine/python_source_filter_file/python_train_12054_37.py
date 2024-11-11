N = int(input())
print(sum(x for x in range(N) if x % 3 != 0 and x % 5 != 0))