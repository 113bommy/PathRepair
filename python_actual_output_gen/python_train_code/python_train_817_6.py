def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(mi())
d = ii()
n = ii()
a = li()
su= 0
for i in range(n):
    su+=(abs(a[i]-d))
print(su)