import sys
input = sys.stdin.readline
n=int(input())
d=[int(i) for i in input().split(' ')]
v=[2*i+1 for i in range(n)]
v.sort(key = lambda x:d[x//2])
for i in range(n-1):print(v[i],v[i+1])
currlen = len(v)        #len of v
for i in range(n):
    if d[v[i]//2] + i == currlen:
        v.append(v[i] + 1)
        currlen += 1
        print(v[-1],v[i] + 1)
    else:
        print(v[ d[v[i]//2] + i - 1],v[i]+1)