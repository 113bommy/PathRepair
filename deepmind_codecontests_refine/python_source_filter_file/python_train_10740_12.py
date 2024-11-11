import sys
input=sys.stdin.readline

for _ in range(int(input())):
    b,w=map(int,input().split())
    if w>3*b+1 or b>3*w+1:
        print("NO")
    elif w==b:
        print("YES")
        for i in range(w):
            print(1,i+1); print(2,i+1)
    elif w>b:
        print("YES")
        col=3
        while(w>b and b>0):
            print(1,col); print(2,col); print(3,col)
            w-=2; b-=1
            if w>b: 
                print(2,col+1)
                w-=1
            col+=2
        if w==1 and b==0:
            print(2,2)
        else:
            for i in range(w):
                print(4,i+3); print(5, i+3)
    elif b>w:
        print("YES")
        col=2
        while(b>w and w>0):
            print(1,col); print(2,col); print(3,col)
            b-=2; w-=1
            if b>w: 
                print(2,col+1)
                b-=1
            col+=2
        if b==1 and w==0:
            print(2,1)
        else:
            for i in range(w):
                print(4,i+3); print(5, i+3)