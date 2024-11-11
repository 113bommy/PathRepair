N = int(input())
a = list(map(int, input().split()))
print(max(a)-min(a)-N+1)
