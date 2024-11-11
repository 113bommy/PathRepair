r = lambda: int(input())
ra = lambda: [*map(int, input().split())]
p = lambda a: print('{:.6f}'.format(a))
a, b = r(), input()
c = ra()
b = list(b)
b = [int(i) for i in b]
k = 0
for i in range(a):
    if k>-1:
        if c[b[i]-1]>b[i] or (c[b[i]-1]>b[i] and k==1):
            b[i] = c[b[i]-1]
            k = 1
        else:
            if k==1:
                k = -1
an = ''
while b!=[]:
    an+=str(b.pop())
print(an[::-1])
