n.k = map(int,input().split())
r,s,p = map(int,input().split())
t = list(input())
for i in range(n-k):
    if t[k+a] == t[a]:
        t[k+a] = 0
xs = t.count('r')*p+ t.count('s')*r+t.count('p')*s
print(x)