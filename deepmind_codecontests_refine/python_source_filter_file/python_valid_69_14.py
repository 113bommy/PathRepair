import sys
 
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.buffer.readline())
def MI(): return map(int, sys.stdin.buffer.readline().split())
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def BI(): return sys.stdin.buffer.readline().rstrip()
def SI(): return sys.stdin.buffer.readline().rstrip().decode()
def li(): return [int(i) for i in input().split()]
def lli(rows): return [li() for _ in range(rows)]
def si(): return input()
def ii(): return int(input())
def ins(): return input().split()

pow2=[]

for i in range(31):
    pow2.append(str(1<<i))
    
def get(s1,s2):
    j=0
    for i in range(len(s1)):
        if s1[i]==s2[j]:
            j+=1
        if j==len(s2):
            break
    return j

t=II()
for _ in range(t):
    n=II()
    num=str(n)
    ans=sys.maxsize
    for i in range(31):
        ans=min(ans,len(num)+len(pow2[i])-2*get(num,pow2[i]))
    print(ans)
    