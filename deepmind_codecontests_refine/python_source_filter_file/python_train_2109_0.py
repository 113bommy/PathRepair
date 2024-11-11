a=int(input())
for i in range(a):
    r=input()
    s=input()
    ans=[]
    count=1
    for i in range(1,len(s)):
        if(s[i]==s[i-1]):
            count+=1
        else:
            ans.append(count)
            count=1
    ans.append(count)
    if(s[0]=='0'):
        if(len(s)<=2):
            print(s)
            continue;
        if(s[-1]=='0'):
            print((ans[0]+1)*'0')
        else:
            print(ans[0]*'0'+'0'+ans[-1]*'1')
            
    else:
        if(len(ans)==1):
            print(s)
            continue;
        if(s[-1]=='0'):
            print(0)
            continue;
        
        print('0'+ans[-1]*'1')


    



             





        
