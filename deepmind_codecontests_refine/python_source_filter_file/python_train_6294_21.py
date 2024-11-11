a=0
b=0
c=0
k=""
f =list()
t=list()
t=[a,b,c]
i=0
while i<3:
    f.append(input())
    i=i+1
i=0

while i<3:
    if(f[i][1]=='>'):
        if(f[i][0]=='A'):
            
            a=a+1
        elif(f[i][0]=='B'):
            b=b+1
        else:
            c=c+1
    if(f[i][1]=='<'):
        if(f[i][0]=='A'):
            
            a=a+1
        elif(f[i][0]=='B'):
            b=b+1
        else:
            c=c+1
    
    i=i+1
if(a==b or b==a or a==c):
    print("Impossible")
else:
    
    t=(sorted([[a,'A'],[b,"B"],[c,"C"]]))
    print(t[0][1]+t[1][1]+t[2][1])
 