n,k=map(int,input().split())
p=((n//2)//(k+1))*(k+1)
a=(1/(k+1))*p
b=(k/(k+1))*p
print (int(a),int(b),int(n-a-b))   