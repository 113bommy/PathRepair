x,y = list(map(int,input().split()))
d = [x,y,y-x,-y,-x,x-y]
l = int(input())
print(d[(l-1)%6]%(10**9+7))
