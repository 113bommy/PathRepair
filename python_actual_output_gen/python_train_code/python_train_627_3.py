n=int(input())
a=[]
rn=0
cnt=0
for i in range(n):
    b,c=map(int,input().split())
    a.append([b,c])
a=a[::-1]
print(a)   
for i in range(n):
    b,c=a[i]
    b+=cnt
    cnt+=(c-b%c)%c
print(cnt)
