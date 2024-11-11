from sys import stdin
k,l,m,n,d = int(stdin.readline()),int(stdin.readline()),int(stdin.readline()),int(stdin.readline()),int(stdin.readline())
for i in range(1,d+1):
    if i%k  and i%l  and i%m  and i%n :
        d -= i
print(d)