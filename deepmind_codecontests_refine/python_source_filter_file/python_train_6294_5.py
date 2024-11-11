
from itertools import permutations
    
def proB(arr):
    for per in list(permutations('ABC')):
        dic={}
        pos=0
        for k in per:
            dic[k]=pos
            pos+=1
        flg=True
        for p in arr:
            i,j=p[0],p[2]
            if(p[1]=='<'):
                if(dic.get(i)<dic.get(j)):
                    continue
                flg=False
                break
            else:
                
                if(dic.get(i)>dic.get(j)):
                    continue
                flg=False
                break
        if(flg):
            return ''.join(dic.keys())
    return 'Impossible'


arr=[]
for i in range(3):
    inp=input()
    arr.append(inp)
    print(proB(arr))