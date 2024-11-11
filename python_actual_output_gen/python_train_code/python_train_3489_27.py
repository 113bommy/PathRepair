a,b=list(map(int,input().split()))
aw,d,bw=0,0,0
for i in range(1,7):
    if(abs(a-i)>abs(b-i)):
        aw=aw+1
    elif(abs(a-i)==abs(b-i)):
        d=d+1
    else:
        bw=bw+1
print(aw,d,bw)
        