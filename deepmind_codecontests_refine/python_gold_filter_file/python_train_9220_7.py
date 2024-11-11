
t=int(input())
a=input()
J=[]
H=[]
for i in range(t):
   
    n, m = (input().split('->'))
    J.append(m)
    H.append(n)
c=J[-1]  
l=H[0]  
d=t%2    
if d==0:
    print('home')
else:
    print('contest')    
    