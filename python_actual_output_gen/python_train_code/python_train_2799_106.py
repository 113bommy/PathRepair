import sys

def data():
    return sys.stdin.readline().strip()
    
    
        
def sp(): return map(int, data().split())    
def l(): return list(sp())

temp=l()
n=temp[0]
k=temp[1]
l=temp[2]
c=temp[3] 
d=temp[4]
p=temp[5] 
nl=temp[6] 
np=temp[7]

kl=k*l
kn=kl/nl
cd=c*d
last=p/np
res=min(kn,cd,last)
print(res/3)