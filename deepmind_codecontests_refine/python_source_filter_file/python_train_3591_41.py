a,b=map(int,input().split())
x=a-b
if(a==1 and b==1):
    print(a)
elif(x>b):
    print(b+1)
else:
    print(b-1)