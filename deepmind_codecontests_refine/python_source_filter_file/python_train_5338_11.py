n = int(input())
l = list(map(int,input().split()))
l.sort()
a = []
for i in range(n//2):
    a.append(l[-i-1])
    a.append(l[i])
if n%2:
    a.append(l[n//2])
print(n//2)
for i in a:
    print(i,end = ' ')
