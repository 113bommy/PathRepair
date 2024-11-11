n, a, b, c = map(int, input().split())
m = [0]+[0]*(n+max(a,b,c)*2)#
m[a]=1;m[b]=1;m[c]=1
for i in range(1, n + 1):
    q = max(m[i - a], m[i - b], m[i - c])
    if q == 0:
        if i not in [a,b,c]: m[i] = 0  
    else :m[i]=q+1
print(m[n],m)