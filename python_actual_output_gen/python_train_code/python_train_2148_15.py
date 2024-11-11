N,M,X,Y = map(int,input().split())
lsx = list(map(int,input().split()))+[X]
lsy = list(map(int,input().split()))+[Y]
if max(lsx) < min(lsy):
    print('No war')
else:
    print('War')