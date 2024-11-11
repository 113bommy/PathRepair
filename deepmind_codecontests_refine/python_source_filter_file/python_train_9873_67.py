n, a, b = map(int, input().split()))
print(sum(i for i in range(1 + n+1) if a <= sum(map(int, str(i)) <=b)))