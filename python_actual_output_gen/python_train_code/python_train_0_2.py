n=int(input())
a=input()
a=list(a)
b=n//11
c=a.count("8")
if c>=b:
    print(b)
elif b<c:
    print(c)
if c==0:
    print("0")
