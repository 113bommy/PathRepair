s1=0
s2=0
o1=0
o2=0
for _ in range (int(input())):
    n1,n2=map(int,input().split())
    s1+=n1
    s2+=n2
    if(n1%2!=0 and n2%2==0):
        o1+=1
    if(n1%2!=0 and n2%2==0):
        o2+=1
if(s1%2==0 and s2%2==0):
    print(0)
elif(s1%2!=0 and s2%2==0):
    print(-1)
elif(s1%2==0 and s2%2!=0):
    print(-1)
elif(s1%2!=0 and s2%2!=0):
    if(o1>0 or o2>0):
        print(1)
    else:
        print(-1)
    
    
    
    
    
