H,W=map(int,input().split())
h,w=map(int,input().split())
print(H*W-H*w-W*h+min(w,h))