l=input()
a=dict()
for i in range(10):
    x=input()
    a[x]=i
print(a)
for i in range(8):
    x=l[10*i:10*i+10]
    print(a[x],end="")
