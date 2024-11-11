t=int(input())
count=0
while count<t:
    count+=1
    a=int(input())
    ans=0
    add=1
    while a>0:
        thing=0
        if a%2==0:
            thing+=int(a//2)
        else:
            thing+=int((a+1)//2)
        ans+=thing*add
        a -= thing
        add+=1
    print(int(ans))
    
    
    
    
