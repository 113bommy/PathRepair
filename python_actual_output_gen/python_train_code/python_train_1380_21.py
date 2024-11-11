n,w=map(int,input().split())
l=sorted(list(map(int,input().split())))
print(max(w,min(l[-1]/2,l[0])*3*n))