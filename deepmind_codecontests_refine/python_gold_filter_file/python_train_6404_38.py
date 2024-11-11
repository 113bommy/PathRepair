n=list(map(int,input()))
m=list(map(int,input()))
for i in range(len(n)):
    if n[i]+m[i]==1:
        print("1",end="")
    if n[i]+m[i]!=1:
        print("0",end="")

            
