h=int(input())
i=1
while h>0:
    h//=2
    i+=1
print((1<<i)-1)
