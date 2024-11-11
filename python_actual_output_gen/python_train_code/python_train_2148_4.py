N,M,X,Y=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))

print("No War") if X<Y and max(x)+1<min(y) else print("War")
