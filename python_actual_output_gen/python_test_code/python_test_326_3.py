n=int(input())
ar1=str(input()).split(' ')
wok={}
out=[]
out.append(n)
out.append(int(ar1[n-2]))
new=int(ar1[n-2])
i=0

while new !=1:
    out.append(int(ar1[new-2]))   
    new=int(ar1[new-2])
for el in out:
    print(el, end=' ')