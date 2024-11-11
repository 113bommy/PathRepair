N=int(input())
d=list(map(int,input().split()))
d=sorted(d)
print(d[N/2]-d[(N/2)-1])