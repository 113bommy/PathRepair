a,b=map(int,input().split())
print(b//(13//min(a+1, 14)+1)*min(1, a//6))
