s=input()
t=set(s)
t=list(t)

def verif(c,s,k):
    compt=0
    for i in range(len(s)):
        compt+=1
        if (c==s[i]):
            compt=0
        if(compt==k):
            return False
    return True
v=[]
right=len(s)
left=0
while(right-left>1):
        mid=(right+left)//2
        
        if(verif(t[0],s,mid)):
            right=mid
        else:
            left=mid
v.append(right)
for i in range(1,len(t)):
    
    
    if(verif(t[i],s,min(v)-1)):
        
        left=0
        right=min(v)
        while(right-left>1):
            mid=(right+left)//2
        
            if(verif(t[i],s,mid)):
                right=mid
            else:
                left=mid
        v.append(right)
print(min(v))
        