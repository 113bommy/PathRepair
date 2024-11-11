from sys import stdin
n,x,y = map(int,stdin.readline().split())
a = list(map(int,stdin.readline().strip().split()))
count = 0
if x>y:
    print(n)
else:
    for i in a:
        if i<=x:
            count+=1
    if count%2==0:
        ans = count/2
    else:
        ans = count//2 + 1
    print(ans)
