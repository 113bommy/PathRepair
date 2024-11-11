n,a,b,c = [int( input()) for i in range(4)]
g = max(0,(n-c)//(b-c))
print (max(n//a,g+(n-g*(b-c))//a))