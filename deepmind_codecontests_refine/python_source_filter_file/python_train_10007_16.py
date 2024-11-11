t=str(input())
s1=t[0:2]
s2=t[3:5]
if s1[::-1]>s2 and int(s1[::-1])<=59:
    t=s1
    print(t+':'+t[::-1])
else:
    if (s1==23):
        t='00'
    else:
        p=int(s1)+1
        if int(p/10)==0:
            t='0'+str(p)
        else:
            t=str(p)
        while(int(t[::-1])>59):
            p+=1
            if int(p/10)==0:
                t='0'+str(p)
            else:
                t=str(p)
    temp=t+':'+t[::-1]
    print(temp)
        