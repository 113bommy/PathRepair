s=input()
t=input()
a=list(s)
b=list(t)
for i in range(len(a)):
    if a[i]==b[i]:
        print("0",end="")
    else:
        print("1",end="")