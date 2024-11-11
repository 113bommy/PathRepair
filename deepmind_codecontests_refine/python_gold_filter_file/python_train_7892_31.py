l = list(map(int, input().split()))
k = int(input())
print(sum(l) + max(l)*((1<<k)-1))