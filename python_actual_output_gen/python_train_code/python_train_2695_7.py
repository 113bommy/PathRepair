from sys import stdin
n = int(input())
l = list(map(int, stdin.readline().rstrip().split(" ")))
l.sort()
c = 0
a = l[0]
b = l[-1]
d = 0
for i in l:
    if a == i:
        c+=1
    else:
        break
for i in range(n-1,-1,-1):
    if l[i]==b:
        d+=1
    else:
        break
if c==d and c==n:
    print(0, 1)
else:
    print(b-a , c*d)