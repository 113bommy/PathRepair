import sys
m,n = map(int,sys.stdin.readline().split())
print(sum (i* (pow(i/m,n)- pow((i-1)/m,n)) for i in range(1,m+1))) 
