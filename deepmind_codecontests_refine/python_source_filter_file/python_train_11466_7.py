n=int(input())
tot=[]
for i in range(n):
    a=input()
    summa=0
    g=1
    for item in a:
        if summa<0:
            g=0
        if item=='(':
            summa+=1
        else:
            summa-=1
    if summa>=0:
        if g==1:
            tot.append(summa)
    elif summa<0:
        f=summa
        l=0
        for m in a:
            if f>1:
                l=1
            if m==')':
                f+=1
            else:
                f-=1
        if l==0:
            if a[-1]!='(':
                tot.append(summa)
dic={}
total=0
for item in tot:
    if item==0:
        dic[0]=0
    else:
        dic[abs(item)]=[0,0]
for item in tot:
    if item>0:
        dic[item][1]+=1
    elif item==0:
        dic[item]+=1
    else:
        dic[abs(item)][0]+=1
for item in dic:
    if item!=0:
        total+=min(dic[item])
    else:
        total+=(dic[item]//2)
print(total)
        
                
        
