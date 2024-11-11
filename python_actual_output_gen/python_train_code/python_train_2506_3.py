b = []
b = input().split()
n = b[0]
a = b[1]
a = int(a)
n = int(n)
if a%2 == 0 :
    c = n-(a//2)
else :
    c = a
print((c+1)//2)
