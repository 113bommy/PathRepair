n=int(input())
s=list(map(int,input().split()))
s.sort()
if s[-1]!=1:
    s[-1]=1
else:
    s[-1]=2

s.sort()
print(' '.join(map(str,s)))