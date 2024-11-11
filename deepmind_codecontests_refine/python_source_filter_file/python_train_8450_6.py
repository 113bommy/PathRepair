n=int(input())
arr=input()
lsum=0
rsum=0
lq=0
rq=0
for i in range(n//2):
    if(arr[i]=='?'):
        lq+=1
    else:
        lsum+=int(arr[i])

for i in range(n//2,n):
    if(arr[i]=='?'):
        rq+=1
    else:
        rsum+=int(arr[i])
#if(lsum==rsum and lq==rq):
#    print("Bicarp")
if(lq+rq%2==1):
    print("Monocarp")
elif((lsum-rsum)//9==(rq-lq)*2 and (lsum-rsum)%9==0):
    print("Bicarp")
elif((rsum-lsum)//9==(rq-lq)*2 and (rsum-lsum)%9==0):
    print("Bicarp")
else:
    print("Monocarp")
    
    
    
