def ii(): return int(input())
def fi(): return float(input())
def si(): return input()
def mi(): return map(int,input().split())
def li(): return list(mi())

n=ii()
a=1 
l=[[0] * 301 for i in range(301)]
b=n*n 
for i in range(n):
    for j in range(n):
        if i%2==0:
            l[i][j]=a
            a+=1
        else:
            l[i][j]=b 
            b-=1

for i in range(n):
    for j in range(n):
        print(l[i][j],end=" ")
    print()