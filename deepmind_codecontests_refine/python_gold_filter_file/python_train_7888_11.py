n=int(input())
d=sorted([list(map(int,input().split()))for i in range(n)],key=lambda x:x[0]+x[1])
c=-float("INF")
an=0
for i,j in d:
    if i-j>=c:
        an+=1
        c=i+j
print(an)