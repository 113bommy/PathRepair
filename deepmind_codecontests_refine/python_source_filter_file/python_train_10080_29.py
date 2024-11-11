s=str(input())
K=int(input())
l=len(s)
a=[]
for i in range(0,l):
    for j in range(i,l):
        a.append(s[i:j+1])
a=sorted(list(set(a)))
print(a[K-1])