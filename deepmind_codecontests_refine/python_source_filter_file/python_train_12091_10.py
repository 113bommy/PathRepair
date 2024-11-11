n,m,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
print(m//(k+1)*(a[-1]*k+a[-2])+(m%(k+1))*a[-2])