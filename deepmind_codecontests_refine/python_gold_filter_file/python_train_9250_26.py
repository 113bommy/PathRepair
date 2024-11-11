n,k,x,y=[int(input()) for _ in range(4)]
print(x*min(k,n)+y*max(n-k,0))