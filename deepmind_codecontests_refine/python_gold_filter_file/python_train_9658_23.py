n=int(input())
a=list(map(int,input().split()))
an=0
for i in range(0,n,2):
    if a[i]%2!=0:
        an+=1
print(an)