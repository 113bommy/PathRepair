w,h,x,y,r=map(int,input().split())
if w-r>=x and h-r>=y and r>x and r>y:
    print('Yes')
else:
    print('No')
