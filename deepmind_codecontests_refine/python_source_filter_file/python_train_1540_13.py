n = int(input().split()[0])
print(max(0, n - sum(map(int, input().split()))))