a=int(input());b=list(map(int,input().split()));k=[];n=0;z=b.count(0)
for i in range(a-1):
    if b[i] in [1,2]:
        if b[i]==b[i+1]:n+=1;b[i+1]=0
        else:
            if b[i+1] ==3:b[i+1]=(3-b[i])
print(n+z)