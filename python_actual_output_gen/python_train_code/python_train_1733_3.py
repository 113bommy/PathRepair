import sys
input=sys.stdin.buffer.readline

t=int(input())
for _ in range(t):
    n=int(input())
    arr=[int(x) for x in input().split()]
    
    zeroBitCnt=[0 for _ in range(30)] #largest no is 10**9
    oneBitCnt=[0 for _ in range(30)] #largest no is 10**9
    for x in arr:
        for i in range(30):
            if (x&(1<<i))>0:
                oneBitCnt[i]+=1
            else:
                zeroBitCnt[i]+=1
    
    ok=False
    for i in range(29,-1,-1):
        if oneBitCnt[i]%2==0:
            continue
        else:
            if oneBitCnt[i]%4==3 and zeroBitCnt[i]%2==0:
                print('Lose')
            else:
                print('Win')
            ok=True
            break
    if ok==False:
        print('Draw')