n=int(input()) 
ax,ay=map(int,input().split()) 
bx,by=map(int,input().split()) 
cx,cy=map(int,input().split()) 
if(ax>bx and ax>bx)or(ax<bx and ax<bx):
    if(ay>by and ay>cy)or(ay<by and ay<cy):
        print("YES") 
    else:
        print("NO") 
else:
    print("NO")