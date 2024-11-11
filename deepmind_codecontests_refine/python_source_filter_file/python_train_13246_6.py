def inp():
    return(int(input()))
def insr():
    s = input()
    return s
def inlt():
    return(list(map(int,input().split())))

def solve(inpl):
    dp=[1]*len(inpl)
    m=0
    for i in range(1,len(inpl)):
        
        k=2
        while(i*k<len(inpl)):
            if inpl[i*k]>inpl[i]:
                print(i,i*k)
                dp[i*k]=max(dp[i*k],dp[i]+1)
            k+=1
        
    return max(dp)

# solve([9])
if __name__ == "__main__":
    r=inp()
    for i in range(r):
#         l2=inlt()
        size=inp()
        inpl=inlt()
        print(solve([0]+inpl))
                    
    