a1,a2,a3=map(int,input().split())
a4,a5,a6=map(int,input().split())
a7,a8,a9=map(int,input().split())
for i in range(1,10**5+1):
    a1=i
    s=a1+a2+a3
    a5=s-(a4+a6)
    a9=s-(a7+a9)
    if(a1+a5+a9==s and a3+a5+a7==s):
        break
    
print(a1,a2,a3)
print(a4,a5,a6)
print(a7,a8,a9)
