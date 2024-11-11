(n,k) = map(int,input().split())
s = input()
if k == 0:
    print(n)
elif n==1 and k==1:
    print(0)
else:
    i = 0
    if s[0]=='1':
        i = 1 
        temp = '1'
        count = 0 
        while(i<n and count!=k):
            if s[i] !='0':
                temp+='0'
                count+=1 
            else:
                temp+=s[i]
            i+=1  
        while(i<n):
            temp+=s[i]
            i+=1
    else:
        i = 1 
        temp = '1'
        count = 1 
        while(i<n and count!=k):
            if s[i] !='0':
                temp+='0'
                count+=1 
            else:
                temp+=s[i]
            i+=1  
        while(i<n):
            temp+=s[i]
            i+=1
    print(temp)