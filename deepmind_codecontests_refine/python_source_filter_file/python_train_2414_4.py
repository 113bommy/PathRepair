n=int(input())
s=input()
k=len(s)
if k%n!=0 or s=="9"*(k):
    print(("1" + (n-1)*"0")*(k//n + 1))
else:
    s1=s[:n]*(k//n)
    # print(s1,s)
    for i in range(k):
        # print(i,s,s1)
        if int(s1[i])<int(s[i]):
            s2=''
            c=1
            for i in range(n -1,-1,-1):
                s2+=str((int(s[i]) + c)%10)
                c=(int(s[i]) + c)//10
                
            print(s2[::-1]*(k//n))
            break
        elif int(s1[i])>int(s[i]):
            print(s1)
            break
        elif i==k-1:
            s2=''
            c=1
            for i in range(k//n-1,-1,-1):
                s2+=str((int(s[i]) + c)%10)
                c=(int(s[i]) + c)//10
                
            print(s2[::-1]*(k//n))
            break
        