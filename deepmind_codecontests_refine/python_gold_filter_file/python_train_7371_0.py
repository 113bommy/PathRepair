s=int(input())
i=1
if s==1: print(4)
elif s==2: print(4)
else:
    while s!=4:
        i+=1
        if s%2==0: s=s/2
        else: s=3*s+1
    print(i+3)