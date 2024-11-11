a,b,c,d=map(int,input().split(" "))
x,y=map(int,input().split(" "))
if (max(a,c)-min(a,c))%x==0 and (max(b,d)-min(b,d))%y==0 and ((max(a,c)-min(a,c)))%2==((max(b,d)-min(b,d)))%2:
    print("YES")
else:
    print("NO")
