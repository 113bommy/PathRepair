s=list(input())
dic={}
for i in range(0,len(s)-1):
    for j in range(i,len(s)):
        ele="".join(s[i:j+1])
        if ele not in dic:
            dic[ele]=1
        else:
            dic[ele]+=1
#print(dic)
        
ans=[]        
for key in dic.keys():
    if dic[key]>=2:

        ans.append(len(key))
ans.sort()
if ans==[]:
    print(0)
else:
    
    print(ans[-1])


        
