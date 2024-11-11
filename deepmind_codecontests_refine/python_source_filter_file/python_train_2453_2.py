s=input()
S=input()
l=[31,28,31,30,31,30,31,31,30,31,30,31]
d={'monday':1,'tuesday':2,'wednesday':3,'thursday':4,'friday':5,'saturday':6,'sunday':7}
value=(d[S]-d[s])%7
if value==0:
    print("YES")
elif value==2 or value==3:
    print("YES")
else:
    print("N0")
