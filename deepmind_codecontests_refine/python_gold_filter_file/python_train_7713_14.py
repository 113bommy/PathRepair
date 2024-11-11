import sys
a=list(map(int,str(input())))
if len(a)==1:
    print("0")
    sys.exit()
y=1
while sum(a)>9:
    a=list(map(int,str(sum(a))))
    y=y+1
print(y)