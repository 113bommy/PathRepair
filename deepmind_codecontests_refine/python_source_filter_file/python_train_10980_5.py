#from math import sqrt
n=input().split()

n=int(n[0])

s=input()

keys=dict()
#keys[s[0]]=1
val=0
for i in range(1,int(len(s)/2)+1):
    
    a=s[i*2-2]
    b=s[i*2-1].lower()
    if (keys.get(a)==None):
        keys[a]=1
    else:
        keys[a]+=1
        
    if (keys.get(b)!=None):
        if (keys[b]>0):
            keys[b]-=1
        else:
            val+=1
    else:
        val+=1
    print(a,b,keys,val)    

print(val)
        
