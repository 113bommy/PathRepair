n=int(input())
l=[]
for i in range(n):
    l.append(list(map(int,input().split())))
print(l)
l.sort()
print(l)
s=0
for i,j in l:
    if (j>=s):
        s=j
        print(i)
    else:
        s=i
print(s)