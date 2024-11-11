from sys import stdin, stdout
import collections
n, m = map(int, stdin.readline().split())
arr = sorted(map(int, stdin.readline().split()))
ans = 0
i = 0
while m>0 and i<n:
    if arr[i]<0:
        ans-=arr[i]
    else:
        break
    i+=1
stdout.write(str(ans)+"\n")