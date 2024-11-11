n = int(input())
a = list(map(int, input().split()))
a.sort()
print(sum(a[-2:-2*n-1:-2]))
