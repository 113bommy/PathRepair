a,b,c = list(map(int,input().split()))

d = a-(b-1)
e = 1*d
f = 0
for i in range(1,b):
    f = f+(2**i)
small = e+f

g=0
h = 0
for i in range(1,c):
    g= g+(2**i)
    h = 2**i
k=a-c
large = g+1+(k*h)

print(small,large)
