def main():
    
    t=int(input())
    allans=[]
    for _ in range(t):
        n,m=readIntArr()
        a=readIntArr()
        
        if m>=n:
            weights=[]
            for i,w in enumerate(a):
                weights.append([w,i])
            weights.sort(key=lambda x:x[0])
            lo1=weights[0][1]+1 #1-index
            lo2=weights[1][1]+1 #1-index
            add=weights[0][0]+weights[1][0]
            
            c=2*sum(a)
            c+=add*(m-n) #every chain adds 2 fridges
            
            allans.append([c])
            for i in range(1,n+1): #make a cycle
                u=i
                v=i+1
                if v>n:
                    v-=n
                allans.append([u,v])
            for __ in range(m-n):
                allans.append([lo1,lo2])
        else:
            allans.append([-1])
    multiLineArrayOfArraysPrint(allans)
    
    return
    
#import sys
#input=sys.stdin.buffer.readline #FOR READING PURE INTEGER INPUTS (space separation ok)
import sys
input=lambda: sys.stdin.readline().rstrip("\r\n") #FOR READING STRING/TEXT INPUTS.
 
def oneLineArrayPrint(arr):
    print(' '.join([str(x) for x in arr]))
def multiLineArrayPrint(arr):
    print('\n'.join([str(x) for x in arr]))
def multiLineArrayOfArraysPrint(arr):
    print('\n'.join([' '.join([str(x) for x in y]) for y in arr]))
 
def readIntArr():
    return [int(x) for x in input().split()]
 
inf=float('inf')
MOD=10**9+7
 
main()