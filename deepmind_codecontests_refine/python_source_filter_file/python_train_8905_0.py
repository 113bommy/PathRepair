n=int(input())
c=1
s=4
for i in range(1,n+1):
    s=i**2*(i+1)**2
    t=int((s-c)/i)
    print(t)
    c=int(s**0.5)
    
