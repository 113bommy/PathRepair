import sys
X, Y = map(int, input().split())

MOD = 1000000007
if (2*X-Y)%3!=0:
    print(0)
    sys.exit()

A = int((2*X-Y)/3)
B = int(X-2*A)

if A<0 or B<0:
    print(0)
    sys.exit()

ans = 1
inv = 1
for i in range(B):
    ans = ans * (A+B-i) %MOD
    inv = inv * (i+1) %MOD

ans = ans * pow(inv, MOD-2, MOD) %MOD
print(ans)
