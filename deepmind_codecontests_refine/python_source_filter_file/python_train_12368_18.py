W,H,x,y = map(int,input().split())

op = 1 if W//2==x and H//2==y else 0
print(W*H/2,op)