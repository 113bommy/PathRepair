import time
from collections import deque 

def inpt():
    return int(input())
def inpl():
    return list(map(int,input().split()))
def inpm():
    return map(int,input().split())
def lcs(X, Y):
    m=len(X)
    n=len(Y)
    LCSuff = [[0 for i in range(n + 1)]
                 for j in range(m + 1)]
    length = 0
    row, col = 0, 0
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 or j == 0:
                LCSuff[i][j] = 0
            elif X[i - 1] == Y[j - 1]:
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1
                if length < LCSuff[i][j]:
                    length = LCSuff[i][j]
                    row = i
                    col = j
            else:
                LCSuff[i][j] = 0
    resultStr = ['0'] * length

    while LCSuff[row][col] != 0:
        length -= 1
        resultStr[length] = X[row - 1]
        row -= 1
        col -= 1

    return ''.join(resultStr)
def solve():
    n = input()
    l=[]
    for i in range(100):
        l.append(str(2**i))
    ans=len(n)+1
    for i in range(100):
        j=0
        length=0
        latest=0
        while j<len(n):
            if length<len(l[i]) and l[i][length]==n[j]:
                length+=1
                latest=j
            j+=1
        ans=min(ans,len(n)+len(l[i])-2*length)
    print(ans)
        
def main():
    #start_time=time.time()
    m=10**9+7
    t = int(input())
    while(t):
        t-=1
        solve()
        
    
    #print('Time Elapsed = ',time.time()-start_time," seconds")
if __name__ == "__main__":
    main()
    