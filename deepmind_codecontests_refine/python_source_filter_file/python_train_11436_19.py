N=int(input())
n=input()
l=0;r=0
for i in n:
    if i=="(":
        r+=1
    else:
        if r:
            r-=1
        else:
            l+=1
print("("*r+n+")"*l)