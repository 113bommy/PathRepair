from sys import stdin, stdout
from math import sqrt
nmbr = lambda: int(input())
lst = lambda: list(map(int, input().split()))
for _ in range(1):#nmbr()):
    n=nmbr()
    # n,m=lst()
    s1=list(input())
    s2=list(input())
    if sorted(s1)!=sorted(s2):
        print(-1)
        continue
    ans=[]
    while 1:
        # print(s1)
        for i in range(n):
            if s1[i]!=s2[i]:
                p=i+1
                while p<n:
                    if s1[p]==s2[i]:
                        break
                    p+=1
                for j in range(p-1,i-1,-1):
                    s1[j],s1[j+1]=s1[j+1],s1[j]
                    ans+=[j+1,j+2]
                break
        if s1==s2:break
    print(len(ans))
    print(*ans)