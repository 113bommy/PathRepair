s=input()
max=0
for i in s:
    if ord(i)>max:
        max=ord(i)
        x=i
a=s.count(x)
print((chr(max))*2)