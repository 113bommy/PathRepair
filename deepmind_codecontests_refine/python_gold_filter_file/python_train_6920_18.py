a,b = map(int,input().split())
diff = abs(a-b)
small = min(a,b)
if(small-diff>=0):
    if((small-diff)%3==2):
        print(diff+2*((small-diff)//3)+1)
    else:
        print(diff+2*((small-diff)//3))
else:
    print(small)