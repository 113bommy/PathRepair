n,k=map(int,input().split())
s=set()
l=[int(i) for i in input().split()]
for i in l:
    if i%k:
        s.add(i)
    else:
        if i//k in s:
            pass 
        else:
            s.add(i)
print(len(s))