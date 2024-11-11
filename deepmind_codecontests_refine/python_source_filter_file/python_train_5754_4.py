"""T=int(input())
for _ in range(0,T):
    n=int(input())
    a,b=map(int,input().split())
    s=input()
    s=[int(x) for x in input().split()]
    for i in range(0,len(s)):
        a,b=map(int,input().split())"""


T=int(input())
for _ in range(0,T):
    n,k,z=map(int,input().split())
    s=[int(x) for x in input().split()]
    """c0=s[0]
    c1=s[0]
    c2=s[0]
    c3=s[0]
    c4=s[0]
    c5=s[0]"""

    c=[]
    

    for i in range(0,z+1):
        if((k-(2*i))>0):
            ct=s[0]
            for j in range(1,(k-(2*i))+1):
                ct+=s[j]
            #print(i,'ct',ct)
            mx=0
            for j in range(0,min(n-1,(k-(2*i))+1)):
                mx=max(mx,s[j]+s[j+1])
            #print('mx',mx)
            ct+=(i*mx)
            c.append(ct)
            
    print(max(c))
            

