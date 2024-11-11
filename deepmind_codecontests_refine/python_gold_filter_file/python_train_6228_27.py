N,M,X,Y = map(int,input().split())
x = [X] + list(map(int,input().split()))
y = [Y] + list(map(int,input().split()))

if max(x) >= min(y):
    print("War")
else:
    print("No War")