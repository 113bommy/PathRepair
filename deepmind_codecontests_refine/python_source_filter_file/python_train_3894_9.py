# import io, os
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
import sys
# sys.stdin=open('input.txt','r')
# sys.stdout=open('output.txt','w')
input=sys.stdin.readline
# sys.setrecursionlimit(300010)
MOD = 1000000007
MOD2 = 998244353
ii = lambda: int(input().strip('\n'))
si = lambda: input().strip('\n')
dgl = lambda: list(map(int,input().strip('\n')))
f = lambda: map(int, input().strip('\n').split())
il = lambda: list(map(int, input().strip('\n').split()))
ls = lambda: list(input().strip('\n'))
lsi = lambda: [int(i) for i in ls()]
let = 'abcdefghijklmnopqrstuvwxyz'
for _ in range(1):
    a,b,c=f()
    l2=[[a%3,a],[b%3,b],[c%3,c]]
    ans=a//3+b//3+c//3+min(a%3,b%3+c%3)
    l2.sort()
    if l2[0][0]==0 and l2[1][0]==2 and l2[2][0]==2 and l2[0][1]>0:
        print(ans+1)
    else:
        print(ans)