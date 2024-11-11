x,y=map(int,input().split())
n=int(input())
d={0:x-y,1:x,2:y,3:y-x,4:-x,5:-5}
print(d[n%6]%(10**9+7))
