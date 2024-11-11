n,d=map(int,input().split())
l=sorted([[*map(int,input().split())]for _ in' '*n])
j=a=A=0
for i in range(n):
    a+=l[i][1]
    while l[i][0]-l[j][0]>=5:
        a-=l[j][1]
        j+=1
    A=max(A,a)
print(A)    