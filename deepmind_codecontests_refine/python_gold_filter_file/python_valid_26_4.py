import math
t=int(input())
for p in range(t):
    s=str(input())
    n=len(s)
    count1=0
    count2=0
    c1=0
    c2=0
    f=0
    if s.count('0')==10 or s.count('1')==10:
        print(10)
    else:
        for i in range(0,n):
            if i%2==0:
                if s[i]=='1' or s[i]=='?':
                    count1+=1 
                if s[i]=='1':
                    c1+=1
            else:
                if s[i]=='1' or s[i]=='?':
                    count2+=1 
                if s[i]=='1':
                    c2+=1
            if i%2==0:
                if c2+math.ceil((n-i-1)/2)<count1:
                    print(i+1)
                    f=1
                    break
                elif c1+((n-i-1)//2)<count2:
                    print(i+1)
                    f=1
                    break
            else:
                if c2+math.floor((n-i-1)/2)<count1:
                    print(i+1)
                    f=1
                    break
                elif c1+math.ceil((n-i-1)//2)<count2:
                    print(i+1)
                    f=1
                    break
        if f==0:
            print(10)