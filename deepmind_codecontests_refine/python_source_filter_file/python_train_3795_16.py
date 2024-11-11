a=int(input())
x=y=g=gg=int(1)
ss=q=int(0)
b=w=str("")
while x<=a:
    b=b+"*"
    w=w+"D"
    x=x+1
s=t=int((a-1)/2)
r=a-2*t
print(s)
while y<=a:
    c=str("")
    c=b[0:s]
    g=g+1
    if g<=t+1:
        s=s-1
    else:
        s=s+1
    o=w[0:r]
    print(c+o+c)
    gg=gg+1
    if gg<=int((a+1)/2):
        r=r+2
    else:
        r=r-2
    y=y+1