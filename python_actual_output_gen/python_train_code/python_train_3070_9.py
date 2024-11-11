n=int(input())
a=list(map(int,input().split()))
c=a.count(1)
d=a.count(2)
cnt=0
while d>0 and c>0:
    d-=1
    c-=1
    cnt+=1
while c-3>0:
    c-=3
    cnt+=1
print(cnt)