#Vasya the Hipstar
a,b = map(int,input().split())
st = ''
if a>b:
    st+=str(b)+' '
    st+=str((a-b)//2)
else:
    st+=str(a)+' '
    st+=str((b-a)//2)
print(st)
