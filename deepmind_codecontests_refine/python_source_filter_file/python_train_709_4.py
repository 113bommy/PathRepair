n=int(input())
a=list(map(int,input().split()))
c=0
d=0
for i in range(n):
    if a[i]%4==0:
        c+=1
    if a[i]%2!=1:
        d+=1
else:
    if (n%2==1 and c==n//2) or c>=d:
        print("Yes")
    else:
        print("No")