n=int(input())
p=list(map(int,input().split()))
s=input()
k=[]

final=[]

for j in range(len(p)):
    p[j]=[p[j],j]
    

def myfunc(c):
    return c[0]

p=sorted(p,key=myfunc,reverse=True)
print(p)
#print(p)

for c in s:
    if(c=='0'):
       final.append(p[len(p)-1])
       k.append(p[len(p)-1])
       p.pop()
    else:
        final.append(k[len(k)-1])
        k.pop()

#print(final)
for i in final:
    print(i[1]+1,end=' ')
print()