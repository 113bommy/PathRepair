Q = int(input())

def solve(x,ans):
    #X = str(x)
#    print(x,ans)
    if len(x) == 1:
        print(ans)
        return
    ret= 0
    for i in range(1,len(x)):
        n = int(x[i:]) * int(x[:i])
        ret = max(ret , n)
        
    #print(ret)
    return solve(str(ret),ans + 1)

for i in range(Q):
    solve(input(),0)

