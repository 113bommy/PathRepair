p=input().rstrip().split(' ')
s=input().rstrip()
x=list(s)
A=int(p[1])-0;
B=int(p[0])-int(p[1])
T=min(A,B)
if T==A:
    for i in range(0,A-1):
        print("LEFT")
    for i in range(0,len(x)):
        print("PRINT",x[i])
        if i!=len(x)-1:
            print("RIGHT")
else:
    for i in range(0,B-1):
        print("RIGHT")
    for i in range(len(x)-1,-1,-1):
        print("PRINT",x[i])
        if i!=0:
            print("LEFT")
    
