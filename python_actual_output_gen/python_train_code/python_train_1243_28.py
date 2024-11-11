n,x=map(int,input().split())
c=0
for i in range(n):
    s=input()
    l=s.split()
    #print(l)
    if l[0]=='+':
        x+=int(l[1])
    elif l[0]=='-' and x>int(l[1]):
        x-=(int(l[1]))
    else:
        c+=1
print(x,c)