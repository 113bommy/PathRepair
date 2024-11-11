total = int(input()) + 1
current = sum(map(int, input().split()))
print(sum(((current + i) % total == 1) for i in range(1, 6)))