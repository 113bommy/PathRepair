t=int(input())
a=list(map(int,input().split()))
countone=0
countzero=0
zero=0
for i in range(t):
    if(a[i]==1):
        countone+=1
        if(zero>0):
            zero-=1
    else:
        zero+=1
        if(zero>countzero):
            countzero=zero
print(countone+countzero)            
