a=input()
c=int(a)
b=a
for i in range(c):
    l=list(map(int,b.strip()))
    if(sum(l)%4==0):
        print(b)
        break
    else:
        b=int(b)
        b=b+1
        b=str(b)
