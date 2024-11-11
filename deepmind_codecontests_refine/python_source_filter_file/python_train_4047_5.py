import sys
input = sys.stdin.readline

n=int(input())
l=[int(input()) for _ in range(n)]
ans=0
re=0
for i in l:
    if i==0:
        re=0
    ans+=(i+re)//2
    re=i%2
print(ans)