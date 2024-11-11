x1,y1,x2,y2=map(int,input().split())
if(x1==x2 or y1==y2):
    print(1,end=' ')
else:
    print(2,end=' ')
if(abs(x1-x2)==abs(y1-y2)):
    print(1,end=' ')
elif((abs(x1-x2)%2!=0 and abs(y1-y2)%2==0) or (abs(x1-x2)%2==0 and abs(y1-y2)!=0)):
    print(0,end=' ')
else:
    print(2,end=' ')
print(max(abs(x1-x2),abs(y1-y2)))