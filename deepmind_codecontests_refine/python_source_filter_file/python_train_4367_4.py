s=[]

while 1:
    l1=input()
    if l1==".":
        break
    l2=input()

    sp1=l1.split('"')
    sp2=l2.split('"')
    
    t=0
    if len(sp1)==len(sp2):
        for i in range(len(sp1)):
            if i%2==1 and sp1[i]!=sp2[i]:
                t+=1
            elif i%2!=1 and sp1[i]!=sp2[i]:
                t+=2


    if sp1==sp2:
        s+=["IDENTCAL"]
    elif t==1:
        s+=["CLOSE"]
    else:
        s+=["DIFFERENT"]

for x in s:
    print(x)


