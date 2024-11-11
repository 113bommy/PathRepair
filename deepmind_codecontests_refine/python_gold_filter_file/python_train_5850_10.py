qc=int(input())
for qq in range(qc):
    c,m,x=map(int,input().split())
    if x>=min(c,m):
        print(min(c,m))
    else:
        print(min(min(c,m),(int)((c+m+x)/3)))