k=int(input())
a=''
if(k>36):
    print(-1)
    exit()
if(k&1):
    a=a+(k//2)*'8'
    a+='4'
else:
    a=(k//2)*'8'
print(a)
    