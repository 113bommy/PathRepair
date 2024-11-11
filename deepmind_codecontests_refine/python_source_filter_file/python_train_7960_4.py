t=input()
n=input()
m={'0':'','1':'','4':'322','6':'53','8':'7222','9':'97222'}
#print(n)
for i,j in m.items():
    #print(i," ")
    n=n.replace(i,j)
n=list(n)
#print(n)
n=sorted(n,reverse=True)
print(''.join(n))
