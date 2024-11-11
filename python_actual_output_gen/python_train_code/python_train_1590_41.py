w,a,b = map(int,input().split())
print(max(min(a,b)-max(a,b)-w,0))