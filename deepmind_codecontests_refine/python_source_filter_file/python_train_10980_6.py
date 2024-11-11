n=int(input())
s=input()
count=0
dic={}
s=s.lower()
for i in range(0,len(s)):
    if(i%2==0):
        dic.setdefault(s[i],0)
        dic[s[i]]=dic[s[i]]+1
    else:
        if(s[i] not  in dic):
            count+=1
        else:
            if(s[i] in dic):
                if(dic[s[i]]==1):
                    dic[s[i]]=dic[s[i]]-1;
                elif(dic[s[i]]==0):
                    count+=1
print(count)