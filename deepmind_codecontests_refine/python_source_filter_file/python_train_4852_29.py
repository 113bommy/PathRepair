n, a = map(int, input().split())
print(min((n+1)//2, max(round(a*n/180) + 1, 2)), n, 1)
