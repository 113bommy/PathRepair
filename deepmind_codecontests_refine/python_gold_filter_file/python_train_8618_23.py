n,m=map(int,input().split())
h=[int(_) for _ in input().split()]
print(len([i  for i in h if i>=m]))