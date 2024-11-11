n,k,x,y = [int(input()) for i in range(4)]
print(x*min(k,n)+y*max(0,n-k))