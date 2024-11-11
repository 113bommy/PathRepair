n,m,X,Y,x,y=map(int,input().split())
a=[abs(X-x),abs(Y-y)]
a.sort()
print("First" if a[0]<5 and a[0]+a[1]<7 else "Second")
