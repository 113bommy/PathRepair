a,b,c,d = map(int,input().split())
if -(-a//c) < -(-d//b):
    print("No")
else:
    print("Yes")