s=list(input())
ones=0
for i in s:
    if(i=='a'):
        ones+=1
    else:
        break
res=[0]*len(s)
for prefix in range(1,len(s)+1):
   # print(prefix)
    string=s[:prefix]
    one=0
    for h in range(prefix-1,-1,-1):
        if(string[h]=='a'):
            one+=1
        else:
            break
            
    if(ones<one):
        if(prefix < len(s) and s[prefix]=='a'):
                continue
        ones=one
            #print("before",s,prefix)
        s[:prefix]=s[:prefix][::-1]
        res[prefix-1]=1
    else:
       # print(prefix,len(s))
        if(prefix < len(s)):
            if(s[0]=='a' and s[prefix]=='a'):
                s[:prefix]=s[:prefix][::-1]
                res[prefix-1]=1
            #print("after",s)
    #print(string,one)
print(s)