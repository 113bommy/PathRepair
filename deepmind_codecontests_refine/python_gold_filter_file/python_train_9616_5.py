n=int(input())
lst=list(map(int,input().split()))
e,o=0,0
for i in range(n):
    if lst[i] % 2==0:
        e+=1
        if e>=2:
            break
    else:
        o+=1
        if o>=2:
            break
if e >=2:
    for i in range(n):
        if lst[i]%2!=0:
            print(i+1)
            break
elif o>=2:
    for i in range(n):
        if lst[i]%2==0:
            print(i+1)
            break