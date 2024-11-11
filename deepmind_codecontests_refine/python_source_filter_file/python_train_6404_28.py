x=list(input().strip())
y=list(input().strip())
f=''
for i,t in zip(x,y):
    if i==t:
        f=f+"0"
    else:
        f=f+"1"
print(int(f))