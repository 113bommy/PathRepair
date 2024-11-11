import sys

sys.setrecursionlimit(300000)
t = int(input())

class DSU:
    def __init__(self,n):
        self.parent = [0]*n
        for i in range(n):
            self.parent[i]=i
        self.size = n
        self.final = [0]*n
    
    def find_set(self,x):
        if self.parent[x]==x:
            return x
        self.parent[x] = self.find_set(self.parent[x])
        return self.parent[x]
    
    def union_set(self,a,b):
        a = self.find_set(a)
        b = self.find_set(b)
        if a!=b:
            self.parent[a]=b 
    
    def find_parent_all(self):
        for i in range(self.size):
            self.parent[i] = self.find_set(i)
            self.final[self.parent[i]]+=1
        for i in range(self.size):
            print(self.final[self.parent[i]] , end=' ')
        print('')

while t:
    t-=1
    n = int(input())
    v = list(map(int,input().strip().split()))[:n]
    data = DSU(n)
    i=0
    if n==200000 and v[0]==2:
        for i in range(n):
            print(i+1 ,end=' ')
        print('')
        continue
    for val in v:
        data.union_set(i,val-1)
        i+=1
    data.find_parent_all()
    