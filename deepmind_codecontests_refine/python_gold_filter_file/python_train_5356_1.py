s=set()
P,N=[int(i) for i in input("").split()]
seen=False
for x in range(N):
    hashval=int(input(""))
    if (hashval+1) % P not in s:
        s.add((hashval+1)%P)
    else:
        seen=True
        break
if seen:
    print(x+1)
else:
    print(-1)
    
