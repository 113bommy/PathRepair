n,a,b,c = [int(x) for x in input().split()]
l = [0]*5000
for i in range(min(a,b,c),n+1):
    l[i] = max(l[i-a],l[i-b],l[i-c])+1
print(l[n])