n,k=map(int,input().split())
ar=list(map(int,list(input())))
li=[1]+[0]*(k-1)
rou=0
for i in range(n):
    j=i%(k)
    rou=i//k
    if(li[j]>ar[i]):
        break
    elif(li[j]<ar[i]):
        if(rou==0):
            li[j]=ar[i]
        else:
            li[j-1]+=1
            break
li=li[::-1]
for i in range(k):
    if(li[i]>9):
        li[i]=0
        li[i+1]+=1
li=li[::-1]
st=''
for i in range(n):
    j=i%(k)
    st+=str(li[j])
print(n)
print(st)