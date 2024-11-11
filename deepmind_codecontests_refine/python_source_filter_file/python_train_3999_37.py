n=int(input())
ss=input()
r=int(ss[1])
n-=1
cnt=0
while n:
    ss=input()
    if r==int(ss[0]):
        cnt+=1
    r=int(ss[1])
    n-=1
print(cnt)