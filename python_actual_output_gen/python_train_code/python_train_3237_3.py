n, m = map(int,input().split())
s = list(map(int,input().split()))
c = 0
d = s[m-1]
for i in range(n):
    if(s[i]>= d and d>0):
        c+=1
print(c)