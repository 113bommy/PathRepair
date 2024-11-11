n=input()
a=0

for i in n:
    if i.isupper():
        a+=1
if a>len(n)-a:
    print(n.upper)
else:
    print(n.lower)
    