n=int(input())
lst=list(map(int,input().split()))
e,o=0,0
for i in range(n):
    if lst[i] % 2==0:
        e+=1
        if e>=3:
            break
    else:
        o+=1
        if o>=3:
            break
if e >=3:
    for i in range(n):
        if lst[i]%2!=0:
            print(i+1)
            break
elif o>=3:
    for i in range(n):
        if lst[i]%2==0:
            print(i+1)
            break