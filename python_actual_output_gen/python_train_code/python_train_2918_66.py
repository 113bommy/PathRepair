a, b = list(map(int, input().split()))
if(a == b):
    print(a,0)
elif(a>b or b>a):
    remaning=a-b
    if(remaning%2==0):
        ans=remaning/2
        print(min(a,b),int(ans))
    elif(remaning==1):
        print(min(a,b),0)
    elif(remaning!=1 and remaning%2!=0):
        ans1=remaning/2
        print(min(a,b), int(abs(ans1)))
    

