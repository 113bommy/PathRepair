s = str(input())
n = int(input())
lis = list(map(int,input().split()))
al = list('abcdefghijklmnopqrstuvwxyz')
c = 0
for i in range(len(s)):
    c += (i+1)*(lis[al.index(al[i])])

max_ = max(lis)
for i in range(len(s)+1,len(s)+n+1):
    c += i*max_
print(c)

