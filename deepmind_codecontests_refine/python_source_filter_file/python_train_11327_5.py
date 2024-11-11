n,m= map(int, input().split())
a = list(map(int, input().split()))
l=[]
for _ in range(m):
    b=list(map(int, input().split()))
    l.append(b)
l.sort(key = lambda x: x[1],reverse=True) 
print(l)
for k in l:
    if(len(a)<=2*n):
        for j in range(k[0]):
            a.extend([k[1]])
a.sort(reverse=True)
print(sum(a[:n]))