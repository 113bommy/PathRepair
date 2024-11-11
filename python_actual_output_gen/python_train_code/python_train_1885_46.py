n=int(input())
l=[]

for i in range(n):
    M=list(map(int,input().split()))
    l+=[M]
for i in range(n):
    a=0
    if l[i][0]*2>=l[i][1] and l[i][0]>1 :
        a=1
    elif l[i][0]==l[i][1] :
        a=1
    print(a*'YES'+(1-a)*'NO')
