n,list=int(input()),list(map(int,input().split()))
max=max(list)
seive=[0]*(max+3)
count=1

for i in list :
    seive[i]=1

for i in range(2,max+3) :
    rslt=0
    for j in range(0,max+3,i) :
        if seive[j]!=0 :
            rslt+=1
    if rslt>count :
        count=rslt
print(count)


