n = int(input())
h = [int(i) for i in input().split()]
diff = max(h)
pos = -1
for i in range(1,n):
    if abs(h[i]-h[i-1]) < diff:
        diff = abs(h[i]-h[i-1])
        pos = i
if abs(h[0]-h[n-1]) < diff:
    print(n,1)
else:
    print(pos-1,pos)