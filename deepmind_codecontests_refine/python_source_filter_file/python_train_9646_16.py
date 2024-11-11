#Kvadrat
from math import sqrt, floor
n=int(input())
n_list=list(str(n))
proverka=[]
for i in ['0','1','4','9','6','5']:
    proverka.append(n_list.count(i))
if proverka.count(0)==6:
    ans=-1
else:    
    i_list=[]
    ans=-1
    for i in range(floor(sqrt(n)),1,-1):
        trig=True
        sovpadenie=0
        position=0
        i_list.clear()
        i_list=list(str(i*i))
        for k in range(len(i_list)):
            for s in range(position, len(n_list)):
                if n_list[s]==i_list[k]:
                    position=s+1
                    sovpadenie+=1
                    break
                elif s==(len(n_list)-1):
                    trig=False    
            if trig:
                if sovpadenie==len(i_list):
                    ans=len(n_list)-len(i_list)
                    break
                else:
                    continue
            else: break
        if ans!=-1: break    
print(ans)            