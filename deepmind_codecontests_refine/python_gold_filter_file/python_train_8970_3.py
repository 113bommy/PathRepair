n,k = map(int,input().split())
a = list(map(int,input().split()))

def check(x,y):
    if x>y:
        return -1
    cnt = 0
    while x<y:
        cnt+=1
        y = y//2
    if x==y:
        return cnt
    else:
        return -1

def find(x):
    ans = []
    for i in range(n):
        c = check(x,a[i])
        if c!=-1:
            ans += [c]
    if len(ans)>=k:
        # print(ans)
        return sum(sorted(ans)[:k])
    else:
        return -1

l = 0
r = 2*10**5+1
# r = 10
ret = 10**18
# while l<r:
#     md = (l+r+1)//2
#     v = find(md)
#     print(md,v)
#     if v!=-1:
#         ret = min(ret,v)
#         l = md
#     else:
#         r = md-1

for i in range(r):
        v = find(i)
        if v!=-1:
            ret = min(ret,v)

# print(l,find(4))
print(ret)