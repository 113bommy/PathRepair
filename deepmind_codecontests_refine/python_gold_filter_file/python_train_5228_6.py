import sys

input = sys.stdin.readline

result = ''
for i in range(int(input())):
    n,k = map(int,input().split())
    thr = min(k//2,n%k)
    ans =  n if n%k == 0 else n//k*k+thr
    result += str(ans) + '\n'
print(result)