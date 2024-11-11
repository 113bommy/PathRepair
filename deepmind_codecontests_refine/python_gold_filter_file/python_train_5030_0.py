def answer():
    last=[0]*(n+1)

    c1,c2,d=0,0,0
    for i in range(n-1,-1,-1):

        if(s[i]=='*'):c1+=1
        else:d+=c1

        last[i]=d
    
    ans=1e15
    c1,c2,d=0,0,0
    for i in range(n):

        if(s[i]=='*'):c1+=1
        else:d+=c1

        ans=min(ans,d+last[i+1])

    return ans
        
    


for T in range(int(input())):
    n=int(input())

    s=input()

    print(answer())
