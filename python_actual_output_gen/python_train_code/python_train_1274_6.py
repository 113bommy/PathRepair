d=0
w=int(input())
maxyear=0
n=list(map(int,input().split()))[:w]
a,b=map(int,input().split())
d=(b-a)
for j in range(0,d):
    maxyear+=n[j]
print(maxyear)