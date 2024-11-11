def cy(n):
    z=n[-1]
    x=''
    x+=z
    x+=n[0:-1]
    return x
n=input()
a=[]
a.append(n)
for i in range(len(n)):
    n=cy(n)
    if n not in a:
        a.append(n)
print(len(a))