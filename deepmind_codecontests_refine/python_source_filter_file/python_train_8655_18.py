x=input()
a=x.count('a')
le=len(x)
if (a*2<=le):
    n=a+(a//2)
    print(n)
else:
    print(le)