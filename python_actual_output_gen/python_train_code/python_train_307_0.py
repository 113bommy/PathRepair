n,a,b,c = [int( input()) for i in range(4)]
g = (n-c)//(b-c)
print (max(n//a,g+(n-g*(b-c))//a))
