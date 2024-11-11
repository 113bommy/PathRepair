from sys import stdin, stdout
#stdin = open('Odd-Even Subsequence.txt', 'r') 
def MI(): return map(int, stdin.readline().split())
def LI(): return list(map(int, stdin.readline().split()))

def isValidOdd(a,n,k,v):
    cnt=0
    for x in a:
        if cnt%2==0:
            if x<=v:
                cnt+=1
        else:
            cnt+=1
    if cnt>=k:
        return True
    return False      
        
def isValidEven(a,n,k,v):
    cnt=0
    for x in a:
        if cnt%2==1:
            if x<=v:
                cnt+=1
        else:
            cnt+=1
    if cnt>=k:
        return True
    return False        

def bs(a,n,k,l,h):
    ans=h
    while (l<=h):
        mid=(l+h)//2
        if isValidOdd(a,n,k,mid) or isValidEven(a,n,k,mid):
            ans=mid
            h=mid-l
        else:
            l=mid+1
    return ans
n,k=MI()
a=LI()
ans=bs(a,n,k,1,10**9)
stdout.write(str(ans)+"\n")    
