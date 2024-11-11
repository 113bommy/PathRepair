x,y = list(map(int,input().split()))
d = [x,y,y-x,-y,-x,x-y]
l = int(input())
print(d[(l%6)-1]%(10**9+7))
