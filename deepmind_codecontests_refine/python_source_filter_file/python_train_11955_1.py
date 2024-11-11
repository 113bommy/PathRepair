n,m = map(int,input().split())
if m == n-1:
  print(0)
  exit()
if 2*m < n:
    print("Impossible")
    exit()

class Unionfind:
     
    def __init__(self,n):
        self.uf = [-1]*n
 
    def find(self,x):
        if self.uf[x] < 0:
            return x
        else:
            self.uf[x] = self.find(self.uf[x])
            return self.uf[x]
 
    def same(self,x,y):
        return self.find(x) == self.find(y)
 
    def union(self,x,y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return False
        if self.uf[x] > self.uf[y]:
            x,y = y,x
        self.uf[x] += self.uf[y]
        self.uf[y] = x
        return True
 
    def size(self,x):
        x = self.find(x)
        return -self.uf[x]

u = Unionfind(n)
a = list(map(int,input().split()))
for i in range(m):
    x,y = map(int,input().split())
    u.union(x,y)
count = 2*(n-m-1)
l = [[] for i in range(n)]
for i in range(n):
    x = u.find(i)
    if x < 0:
        l[i].append(a[i])
    else:
        l[x].append(a[i])

ans = 0
h = []
for i in range(n):
    if l[i]:
        l[i].sort()
        ans += l[i][0]
        count -= 1
        for j in l[i][1:]:
            h.append(j)
h.sort()
ans += sum(h[:count])
print(ans)