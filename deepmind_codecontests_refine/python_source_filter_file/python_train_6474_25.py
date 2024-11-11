import math
n , m = map(int , input().split())
MOD = int(1e9 + 7)
ans = 1;
my = pow(2,n,MOD);
print(pow(my,m,MOD))
