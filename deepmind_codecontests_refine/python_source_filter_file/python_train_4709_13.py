x=input()
if len(x)==1:
    if x.islower():
        x=x.upper()
    else:
        x=x.lower()
elif x[0].islower() and x[1:].isupper():
    p=x[0]
    q=x[1:]
    p=p.upper()
    q=q.lower()
    c=p+q
elif x.isupper():
    x=x.lower()
print(x)
    