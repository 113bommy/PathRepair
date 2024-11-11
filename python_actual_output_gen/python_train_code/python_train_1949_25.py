x,y = list(map(int,input().split()))
a = [y-x, y+x+1, -y-x+1, -y-x+2]
a = [i for i in a if i>=0]
print(min(a))
