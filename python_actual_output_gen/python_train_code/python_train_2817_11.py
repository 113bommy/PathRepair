from itertools import accumulate as ac
n=int(input())
l=list(ac(map(int,input().split())))
a=l[-1]
print(min(abs(a-2*i) for i in l))