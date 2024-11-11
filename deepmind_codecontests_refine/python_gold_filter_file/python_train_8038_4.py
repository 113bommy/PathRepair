
def main():
    
    def calcTotalTime(easyCnts,hardCnts):
        return a*easyCnts+b*hardCnts
    
    m=int(input())
    allans=[]
    for _ in range(m):
        n,T,a,b=readIntArr()
        ease=readIntArr()
        t=readIntArr()
        et=[]
        easyCnts=0
        hardCnts=0
        for i in range(n):
            et.append([ease[i],t[i]])
            if ease[i]==0:
                easyCnts+=1
            else:
                hardCnts+=1
        et.append([-1,0]) # add 1 more at time 0 that is neither easy nor hard
        n+=1
        et.sort(key=lambda x:x[1]) # sort by time asc
        easyCumu=[0 for _ in range(n)]
        hardCumu=[0 for _ in range(n)]
        for i in range(n):
            if et[i][0]==0:
                easyCumu[i]+=1
            elif et[i][0]==1:
                hardCumu[i]+=1
            if i>0:
                easyCumu[i]+=easyCumu[i-1]
                hardCumu[i]+=hardCumu[i-1]
        
        maxScore=0
        # print('et:{}'.format(et))
        for i in range(n):
            e=easyCumu[i] # at least this number of easy
            h=hardCumu[i] # at least this number of hard
            # print('i:{} e:{} h:{} total:{}'.format(i,e,h,calcTotalTime(e,h)))
            if calcTotalTime(e,h)>T or (i+1<n and calcTotalTime(e,h)>=et[i+1][1]):
                continue
            #binary search to find max e
            binn=easyCnts
            while binn>0:
                while e+binn<=easyCnts \
                    and calcTotalTime(e+binn,h)<=T \
                    and (i==n-1 or calcTotalTime(e+binn,h)<et[i+1][1]):
                    e+=binn
                binn//=2
            #binary search to find max h
            binn=hardCnts
            while binn>0:
                while h+binn<=hardCnts \
                    and calcTotalTime(e,h+binn)<=T \
                    and (i==n-1 or calcTotalTime(e,h+binn)<et[i+1][1]):
                    h+=binn
                binn//=2
            # print('i:{} e:{} h:{} total:{} T:{}'.format(i,e,h,calcTotalTime(e,h),T))
            maxScore=max(maxScore,e+h)
        allans.append(maxScore)
    # print('here')
    multiLineArrayPrint(allans)
    
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