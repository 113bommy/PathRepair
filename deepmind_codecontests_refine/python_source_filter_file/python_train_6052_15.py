#double underscore makes a class variable or a class method private
mod = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
l=[[0]*4 for i in range(4)]
s=si()
hor = [[1, 2], [2, 2], [3, 2], [4, 3]]
ver = [[1, 1],[3, 1]]
o,z=0,0
for i in s:
    if i=='1':
        print(*hor[o%4])
        o+=1
    else:
        print(*ver[z%2])
        z+=1
        