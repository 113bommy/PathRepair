# http://codeforces.com/problemset/problem/985/A

def min_step():
    n=int(input())
    Place=list(map(int,input().split()))
    print(min(sum([abs(x-y) for x,y in zip([x for x in range(1,n+1,2)],Place)]),sum([abs(x-y) for x,y in zip([x for x in range(2,n+1,2)],Place)])))

if __name__=='__main__':
    min_step()
