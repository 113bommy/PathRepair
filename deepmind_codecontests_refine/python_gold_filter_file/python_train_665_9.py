n = int(input())
y=input().split()
s=0
m=0
i=0
while i < n:
    x =int(max(int(y[0]),int(y[-1])))
    if i%2!=0:
        s+=x
        y.remove(str(x))
    else:
        m+=x
        y.remove(str(x))
    i+=1
print(m,s)