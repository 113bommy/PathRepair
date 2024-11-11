n=int(input())
s=input()
l=[0]*n
for i in s:
    try: 
        k=int(i)
        l[k]=0
    except ValueError:
        if i=='L':
            l[l.index(0)]=1
        else:
            l.reverse()
            l[l.index(0)]=1
            l.reverse()
for i in l:
    print(i,end="")