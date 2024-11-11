n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
a_ = sorted(a)
b_ = sorted(b)
f = sum(b_[i]<a_[i] for i in range(n))
if f:
    print("No")
    exit(0)
g = sum(b_[i-1]>=a[i] for i in range(1,n))
if g:
    print("Yes")
    exit(0)
da = dict()
for i in range(n):
    da[a_[i]] = i
ca = list(map(lambda x:da[x],a))
db = dict()
for i in range(n):
    db[b_[i]] = i
cb = list(map(lambda x:db[x],b))
cb2 = [None]*n
for i in range(n):
    cb2[ca[i]] = cb[i]
cnt = 1
c = cb2[0]
while c:
    c = cb2[c]
    cnt = 1
if cnt ==  n:
    print("No")
else:
    print("Yes")