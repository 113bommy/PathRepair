import math
a  = int (input())
b = int (input())
s = math.fabs(b-a )
r = s/2
s = int(s)
r = int(r)
t = 0
n =0
f = 0
e = r+1
w =0
q = 0

if s%2!=0:
    for i in range(r):
        n+=i+1
        
        
    for j in range(r+1):
        t+= j+1
        
        print(n+t)
if s%2==0:
    if s == 0:
        print("0")
    for i in range(r):
        n+=i+1
        print(n*2)
        



        
    
