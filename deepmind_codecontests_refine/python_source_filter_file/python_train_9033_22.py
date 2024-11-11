n,k = map(int, input().split())
H = sorted(list(map(int, input().split())))
print(sum(H[:-k]) if k >= n else 0)