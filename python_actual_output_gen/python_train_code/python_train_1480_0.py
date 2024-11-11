N=32768
p=[i for i in range(N)]
for i in range(2,int(N**0.5)+1):
    if p[i]:
        for j in range(i*i,N,i):p[j]=0
p=sorted(set(p))[2:]
print(p)
while 1:
    n=int(input())
    if n==0:break
    c=0
    if n&1:c=int(n-2 in p)
    else:
        for x in p:
            if x>n//2:break
            if n-x in p:c+=1
    print(c)