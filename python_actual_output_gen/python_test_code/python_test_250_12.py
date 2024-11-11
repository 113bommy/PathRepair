n=int(input())
h=list(map(int,input().split(" ")))
m=0
a=False
for i in h:
    if i<m+1:
        a=True
    if i>m:
        m=i
print('YNeos'[a::2])