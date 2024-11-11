n, m, x, y = map(int, input().split())
a = max(list(map(int, input().split())))
b = min(map(int, input().split()))
print(['War', 'No War'][any((a<i<=b) for i in range(x,y+1))])