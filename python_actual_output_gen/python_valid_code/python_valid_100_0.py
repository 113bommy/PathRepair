import sys
input=sys.stdin.readline

n,m=list(map(int,input().split()))
a=[]
for i in range(n):
    a.append([min(list(map(int,input().split()))),i+1])
print(max(a)[1])