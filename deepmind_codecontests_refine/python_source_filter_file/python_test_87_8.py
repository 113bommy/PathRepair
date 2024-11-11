import sys,math
#s#ys.stdin=open('input.txt','r')
#sys.stdout=open('output.txt','w')




def solve():
    n=int(input())
    l=list(map(int,input().split()))
    #count=0
    i=0
    ans=0
    for i in range(1,len(l)+1):
        print(l[i-1],i)
        ans=max(ans,l[i-1]-i)
    print(ans)




t=int(input())
while(t!=0):
    solve()
    t-=1
