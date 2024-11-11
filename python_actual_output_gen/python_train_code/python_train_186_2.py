n,a=map(int, input().split())
x=list(map(int, input().split()))
x=[i-a for i in x]
d={0:0}
for i in x:
    for j,k in list(d.items()):
        d[i+j]=d.get(i+j,0)+k
print(d[0])
#sample code.
