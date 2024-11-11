n=int(input())
a=list(map(int,input().split()))
d=[0]*n
for i in a:
    d[i-1]+=1
for j in d:
    print(j)