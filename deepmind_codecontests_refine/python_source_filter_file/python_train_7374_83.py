N=input()
c=0
for i in range(N):
    l,r=(int(i) for i in input().split())
    c+=r-l+1
print(c)