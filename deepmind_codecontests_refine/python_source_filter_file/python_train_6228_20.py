n,m,x,y=map(int,input().split())
xi=[int(_) for _ in input().split()]
yi=[int(_) for _ in input().split()]
print('War' if max(xi) >= min(yi) else 'No War')