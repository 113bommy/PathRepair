I=lambda:map(int,input().split());n,m=I();a=sorted(I());
print(min(j-1 for i,j in zip(a,a[n-1:])))