a,b=input().split()
a=int(a)
b=int(b)
c=input().split()
for i in range(len(c)):
    c[i]=int(c[i])
x=0
t=0
for i in range(a-2):
    while (t<a and c[t]<=c[i]+b):
        t=t+1 
    x=x+t-i-1+(t-i-1)*(t-i-2)/2
print(int(x))