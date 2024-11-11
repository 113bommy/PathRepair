A=input()
B=input()

Fa=A.count('4')

Fb=B.count('4')

if(Fa==Fb):
    ans=0
    for i in range(len(A)):
        if(A[i]!=B[i]):
            ans+=1
    print(ans//2)

else:
    cnt=abs(Fa-Fb)
    ans=0
    for i in range(len(A)):
        if(A[i]==B[i]):
            continue
        if(cnt):
            ans+=2
            cnt-=1
        else:
            ans+=1
    print(ans//2)
            
