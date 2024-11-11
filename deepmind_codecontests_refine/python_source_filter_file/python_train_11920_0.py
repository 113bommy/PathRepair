n=int(input())
S=str(input())
l=S.split(' ')
M='0 0'
f=0
L=[int(i) for i in l]
for i in range(n):
    if L[i]!=i+1 and f==0:
        j=L[i]
        if L[j:]!=[i for i in range(j,n+1)]:
            print('0 0')
            f=2
            break
        else:
            M=str(i+1)+' '+str(j)
            f=1
    if L[L[i]-1]!=i+1:
        print('0 0')
        f=2
        break
if f!=2:
    print(M)