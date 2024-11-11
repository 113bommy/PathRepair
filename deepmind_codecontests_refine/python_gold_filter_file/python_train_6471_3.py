mod = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
n=ii()
s=''
for i in range(1,5001):
    s+=str(i)
print(s[n-1])