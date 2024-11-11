a,b=map(int,input().split())
s=str(input())
s1=""
s2="1"
s3="0"
if(a==1 and b==1):
    print(1)
elif(a==1 and b==0):
    print(s)
else:
    if(int(s[0])>1 and b>0):
        s1=s1+s2
        b=b-1
    else:
        s1=s1+s[0]
    for i in range(1,a):
        if(b>0):
            if(int(s[i])>0):
               s1=s1+s3
               b=b-1
            else:
                s1=s1+s[i]
        else:
            s1=s1+s[i]
    print(s1)
            
