K, T = map(int, input().split())
a = list(map(int, input().split()))
print(max(a)-(sum(a)-max(a))-1, 0)