a=input()
ans=[]
i=0
while (i<len(a)-1):
    if a[i]=='.':
        ans.append(0)
        i+=1
    else:
        if a[i+1]=='.':
            ans.append(1)
        else:
            ans.append(2)
        i+=2
if a[-1]=='.' and i!=len(a):
    ans.append(0)
print(*ans,sep='')
            
    


        
