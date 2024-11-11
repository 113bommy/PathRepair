s = int(input())
k = 10**9
x = (k-s%k)%k
y = (s+x)/k
print(0,0,k,1,x,y)