import sys
input = sys.stdin.readline

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

def main():
    n = int(input())
    xy = [list(map(int,input().split())) for i in range(n)]
    xy2 = [[x[0],x[1],i] for (i,x) in enumerate(xy)]
    xy2.sort()
    u = Unionfind(n)

    l = []
    for x,y,ind in xy2:
        M = y
        le = ind
        while l and xy[l[-1]][1] < y:
            v = l.pop()
            if M < xy[v][1]:
                M = xy[v][1]
                le = ind
            u.union(ind,v)
        l.append(le)
    for i in range(n):
        print(u.size(i))

if __name__ == "__main__":
    main()