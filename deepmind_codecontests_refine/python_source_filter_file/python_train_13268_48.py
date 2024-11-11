n=int(input())
c=0
for i in range(n):
    s,m=list(map(int,input().split()))
    if m>s:
        c+=1
print(c)