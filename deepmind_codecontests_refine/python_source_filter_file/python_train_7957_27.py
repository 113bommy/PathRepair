import string
s=input()
t=int(input())
l=list(map(int,input().split()))
a=string.ascii_lowercase
for i in range(t):
    s=s+a[l.index(max(l))]
cnt=0
i=1
for x in s:
    cnt=cnt+i*(l[s.find(x)])
    i=i+1
print(cnt)