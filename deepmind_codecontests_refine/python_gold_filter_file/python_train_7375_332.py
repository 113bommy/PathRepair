n = int(input())
print(sum(sorted(map(int, input().split()))[-2:n-1:-2]))