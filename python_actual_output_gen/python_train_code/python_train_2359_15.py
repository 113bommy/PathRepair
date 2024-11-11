code=input()
ans=''
i=0
while i<len(code)-1:
    if(code[i]=='.'):
        ans+='0'
    elif(code[i]=='-'):
        if(code[i+1]=='.'):
            ans+='1'
            i+=1
        else:
            ans+='2'
            i+=1
    i+=1
print(ans)