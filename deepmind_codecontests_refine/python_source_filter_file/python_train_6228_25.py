N,M,X,Y=map(int,input().split())
x=max(map(int,input().split()))
y=min(map(int,input().split()))
print('War' if x>y or Y <= x or y <= X else 'No War')