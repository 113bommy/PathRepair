import sys
input = sys.stdin.readline

N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))

compression_dict={a: ind+1 for ind, a in enumerate(sorted(set(A)|set(B)))}

SA=sorted(A)
SB=sorted(B)

for i in range(N):
    if SA[i]>SB[i]:
        print("No")
        sys.exit()

for i in range(N-1):
    if SB[i]>=SA[i+1]:
        print("Yes")
        sys.exit()

AB=[(B[i],A[i]) for i in range(N)]
AB.sort()

DICT={a:ind for ind,a  in enumerate(A)}

Group=[i for i in range(N)]# グループ分け.Group[i]=jのときiとjは同じグループ

def find(x):# find(a)=find(b)のとき同じグループ
    while Group[x] != x:
        x=Group[x]
    return x

def Union(x,y):  # xとyが同じグループになるよう更新
    if find(x) != find(y):
        Group[find(y)]=Group[find(x)]=min(find(y),find(x))

for i in range(N):
    _,a=AB[i]

    Union(DICT[a],i)

if len(set([find(i) for i in range(N)]))==1:
    print("No")
else:
    print("Yes")
