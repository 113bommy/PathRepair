
def main():
    
    n=int(input())
    a=readIntArr()
    
    arr=[] # store a[i]%2 if not removed. If removed, store -1
    items=set(range(1,n+1))
    for x in a:
        if x==0:
            arr.append(-1)
        else:
            arr.append(x%2)
            items.remove(x)
    itemModCnts=[0,0]
    for x in items:
        itemModCnts[x%2]+=1
        
    dp=makeArr(inf,[n,n+1,n+1,2]) #dp[i][used 0 cnts][used 1 cnts][currIsOdd] is the min complexity achievable
    if arr[0]==-1:
        dp[0][0][1][1]=0 # put a %2=1 item
        dp[0][1][0][0]=0 # put a %2=0 item
    else:
        dp[0][0][0][arr[0]%2]=0
    for i in range(1,n):
        for j in range(n):
            for k in range(n):
                if arr[i]==-1:
                    if j>0: # place even number
                        dp[i][j][k][0]=min(dp[i][j][k][0],dp[i-1][j-1][k][0]) # prev was even
                        dp[i][j][k][0]=min(dp[i][j][k][0],dp[i-1][j-1][k][1]+1) # prev was odd
                    if k>0: # place odd number
                        dp[i][j][k][1]=min(dp[i][j][k][1],dp[i-1][j][k-1][0]+1) # prev was even
                        dp[i][j][k][1]=min(dp[i][j][k][1],dp[i-1][j][k-1][1]) # prev was odd
                else:
                    dp[i][j][k][arr[i]]=min(dp[i][j][k][arr[i]],dp[i-1][j][k][arr[i]])
                    dp[i][j][k][arr[i]]=min(dp[i][j][k][arr[i]],1+dp[i-1][j][k][arr[i]^1])
    ans=min(dp[n-1][itemModCnts[0]][itemModCnts[1]][0],dp[n-1][itemModCnts[0]][itemModCnts[1]][1])
    print(ans)
    return
    
import sys
input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
# input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.

def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
# def readFloatArr():
#     return [float(x) for x in input().split()]
 
def makeArr(defaultVal,dimensionArr): # eg. makeArr(0,[n,m])
    dv=defaultVal;da=dimensionArr
    if len(da)==1:return [dv for _ in range(da[0])]
    else:return [makeArr(dv,da[1:]) for _ in range(da[0])]
 
def queryInteractive(x,y):
    print('? {} {}'.format(x,y))
    sys.stdout.flush()
    return int(input())
 
def answerInteractive(ans):
    print('! {}'.format(ans))
    sys.stdout.flush()
 
inf=float('inf')
MOD=10**9+7


for _abc in range(1):
    main()