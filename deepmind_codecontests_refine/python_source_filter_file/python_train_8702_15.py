#n=int(input())
#n,m=map(int,input().split())
#arr=list(map(int,input().split()))\
#for i in range(m):
x1,y1,x2,y2=map(int,input().split())
a,b=map(int,input().split())
if abs(x2-x1)%a==0 and abs(y2-y1)%b==0:
    if abs(x2-x1)//a==abs(y2-y1)//b:
        print("YES")
    else:
        print("NO")
else:
    print("NO")