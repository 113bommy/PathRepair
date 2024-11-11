ans="#Black&White"
n,c=map(int,input().split(" "))
i=0;b=0
color="YCMG"
while(i<n):
    li=input().split(" ")
    if(b==0):
        for j in li:
            if color.find(j)>-1:
                b=1
                ans="#Color"
                break
    i+=1
print(ans)
