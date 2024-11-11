a,b=list(map(int,input().split()))
wina,winb,draw=0,0,0
for i in range(1,6):
    if(abs(0-a)>abs(6-b)):
        wina+=1
    elif(abs(0-a)<abs(6-b)):
        winb+=1
    else:
        draw+=1
print(wina,end=" ")
print(draw,end=" ")
print(winb,end=" ")