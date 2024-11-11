mod = 10 ** 9 + 7
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
n=ii()
l=[]
ln=0
for i in range(1,82):
    if n-i>0:
        if sum(int(i) for i in str(n-i))+n-i==n:
            l.append(n-i)
            ln+=1
print(ln)
[print(i) for i in l]
