import sys, io, os

if os.environ['USERNAME']=='kissz':
    inp=open('in2.txt','r').readline
    def debug(*args):
        print(*args,file=sys.stderr)
else:
    inp=input
    def debug(*args):
        pass

# SCRIPT STARTS HERE
def solve():
    n,m=map(int,inp().split())
    E=['']*(n*n)
    for i in range(n):
        for j,c in enumerate(inp().strip()):
            E[n*i+j]=c
    if m%2:
        print('YES')
        print(*([1,2]*m)[:m+1])
        return
    for i in range(n):
        for j in range(i+1,n):
            if E[n*i+j]==E[n*j+i]:
                print('YES')
                print(*([i+1,j+1]*m)[:m+1])
                return
    for i in range(3):
        if i==2 and n==2:
            print('NO')
            return
        if 'a' in E[n*i:n*(i+1)] and 'b' in E[n*i:n*(i+1)]:
            j=k=0
            while E[n*i+j]!='a': j+=1
            while E[n*i+k]!='b': k+=1
            if m%4==0:
                print('YES')
                print(*(([i+1,j+1]*(m//4))+([i+1,k+1]*(m//4))+[i+1]))
            else:
                print('YES')
                print(*(([k+1,i+1]*(m//4))+[k+1,i+1,j+1]+([i+1,j+1]*(m//4))))
            return
    print('NO') # not used!
        

for _ in range(int(inp())):
    solve()
