def popcount(n):
    return bin(n).count('1')
N=int(input())
X=input()
xl=list(X)
X=int(X,2)
a=popcount(X)
#1が減った時
if a==1:
    xi=0
else:
    xi=X%(a-1)
#1が増えたとき
xd=X%(a+1)

for i in range(N):
    if xl[i]=='1':
        if a==1:
            print(0)
            continue
        else:
            k=pow(2,N-1-i,a-1)
            x=(xd-k)%(a-1)
    else:
        k=pow(2,N-1-i,a+1)
        x=(xi+k)%(a+1)
    count=1
    while x!=0:
        x%=popcount(x)
        count+=1
    print(count)