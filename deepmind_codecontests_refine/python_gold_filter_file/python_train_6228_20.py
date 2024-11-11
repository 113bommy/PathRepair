n,m,x,y=map(int,input().split())
xi=[int(_) for _ in input().split()]+[x]
yi=[int(_) for _ in input().split()]+[y]
print('War' if max(xi) >= min(yi) else 'No War')