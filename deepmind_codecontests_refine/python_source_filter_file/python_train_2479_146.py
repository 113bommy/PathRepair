H,W = map(int,input().split())
h,w = map(int,input().split())

print(H*W-h*H-w*W+h*w)