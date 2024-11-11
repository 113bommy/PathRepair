import sys
input = sys.stdin.readline

L = int(input())
ans = [[1,2,0],[1,2,1]]#L=2の答え
S=1
T=2
def recursion(x):
    global T
    if x == 2:
        return
    
    if x%2==1:
        recursion(x-1)
        ans.append([S,T,x])
        
    else:
        recursion(x//2)
        for i in range(len(ans)):
            ans[i][2] = 2*ans[i][2]
        T += 1
        ans.append([T-1,T,0])
        ans.append([T-1,T,1])
    return

recursion(L)
print(T,len(ans))
for i,j,k in ans:
    print(i,j,k)
        


