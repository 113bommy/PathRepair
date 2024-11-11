s=input()
t=input()
a=list(s)
b=list(t)
for i in range(len(a)):
    if a[i]==b[i]:
        print("1",end="")
    else:
        print("0",end="")