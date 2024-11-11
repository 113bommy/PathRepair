n = int(input())
l=[]
for i in range(n):
    l.append(int(input()))
c = l[0]
for i in range(0,n-1):
    c = c + (abs(l[i] - l[i+1]))
print(c+2*n-1)