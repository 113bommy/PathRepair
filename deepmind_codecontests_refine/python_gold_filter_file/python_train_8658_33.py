import pdb
import sys
#n, l, r = input()
x = sys.stdin.readline()
n,l,r = list(map(int,x.split()))
min_sum = 0
max_sum = 0
for summer in range(l):
    min_sum += pow(2, summer)
 
min_sum += (n - l)
max_sum = 0
for summer in range(r):
    max_sum += pow(2, summer)
max_sum += pow(2, (r-1)) *(n - r)
print(min_sum, max_sum)
