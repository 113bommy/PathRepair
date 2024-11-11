a, b =input().split('+')
c,d = b.split('=')

if (len(a)+len(c))==len(d):
    print(a+"+"+c+"="+d)
elif len(d)!=1 and (len(a)+len(c)+1)==len(d)-1:
    print(a+"+"+c+"|"+"="+d[:-1])
elif len(c)!=1 and (len(a)+len(c)-1)==len(d)+1:
    print(a+"+"+c[:-1]+"="+d+"|")
elif len(a)!=1 and (len(a)-1+len(c))==len(d)+1:
    print(a[:-1]+c+"="+d+"|")
else:
    print("Impossible")