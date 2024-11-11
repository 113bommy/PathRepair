n=int(input())
s=input()

x=0
r=0
for i in s:
    if i=='x':
        x+=1
        print(x)
        if x>2:
            r+=1
    else:
        x=0
print(r)