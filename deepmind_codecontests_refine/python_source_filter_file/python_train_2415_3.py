#Ashish Sagar
n=int(input())
n1=n 
s=set()
for i in range(2,int(n1**(0.5))):
    while(n1 % i == 0):
        n1=n1//i
        s.add(i)
		
if n1>1:
    s.add(n1) 
if len(s)==1:
    s=list(s)
    s.sort()
    print(s[0])
else:
    print(1)