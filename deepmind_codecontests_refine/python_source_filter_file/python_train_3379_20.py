i=int(input())
j=input().split()
k=input().split()
n=0
for p in range(1,len(j)):
    n=n+int(j[p])
for t in range(1,len(k)):
    if k[t] not in j:
        n=n+int(k[t])
if n==(1+i)*i/2:
    print('I become the guy.')
else:
    print('Oh, my keyboard!')
