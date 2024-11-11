n=int(input())
s=input()
d={}
for i in s:
    if(i in d):
        d[i]+=1
    else:
        d[i]=1
if('8' in d):
    x=d['8']
    del d['8']
    d['8']=x
c=0

while(True):
    if('8' in d and d['8']>=1):
        d['8']-=1
        s=0
        for k,v in d.items():
            if(v>0):
                # if(k=='8'):
                #     s+=1
                #     d[k]-=1
                s+=v
                if(s==10):
                    c+=1
                    d[k]=0
                    break
                if(s>10):
                    d[k]=s-10
                    c += 1
                    break
                else:
                    d[k]=0
    else:
        break
print(c)
