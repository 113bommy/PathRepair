def judge(x):
    count = 0
    for hi in h:
        count += (hi - b*x + c-1)//c 
    if count<=x:
        return True
    else:
        return False

n,a,b=map(int,input().split())
h = [int(input()) for _ in range(n)]

c= a-b

ng = 0
ok = 10**9

while ok - ng > 1:
    mid = (ng+ok)//2
    if judge(mid):
        ok = mid
    else:
        ng = mid
        
print(ok)