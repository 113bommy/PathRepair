x=input()
x=x.split()
y=[int(p) for p in x]


lst=[]

x=input().split()
z=[int(p) for p in x]

x=input().split()
w=[int(p) for p in x]


tl=max(z)               
temp=0
if(tl>=2*min(z)):
        temp=1
else:
        for x in z:
                if(2*x>tl):
                        tl=2*x
                        temp=1
                        break;
if(temp==1):
        
        for x in w:
                if(x>tl):
                        temp=1
                else:
                        temp=0
                        break;
if(temp==0):
        print("-1")
else:print(tl)
                
                        



