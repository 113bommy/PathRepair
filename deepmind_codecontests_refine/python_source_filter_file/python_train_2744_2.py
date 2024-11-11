mod = 10 ** 9 + 7
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
n=ii()
l=[]
mx=0
for i in range(n):
    l.append(si())
c=1
for i in range(1,n):
    c=c+1 if l[i-1]==l[i] else 1
    mx=max(mx,c)
print(mx)