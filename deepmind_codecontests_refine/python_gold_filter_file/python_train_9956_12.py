a,b,c=input().split()
a,b,c=int(a),int(b),int(c)
rem1=-1
flag=0
count=0
d=a%b
while d!=rem1 and count<=1000000:
    rem1=d%b
    count+=1
    d=d*10
    q=d//b
    if q==c:
        print(count)
        flag=1
        break
    d=d%b
if flag==0:
    print(-1)
    
        
        
