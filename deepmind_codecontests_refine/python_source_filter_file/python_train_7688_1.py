import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")

n = int(input())
a = [None]*n
for i in range(n):
    a[i] = int(input())
ans = a[0]-1
prev = 1
for i,num in enumerate(a[1:]):
    if prev+1<num:
        while num-(prev+1)>0:
            v = (num-1)//(prev+1)
            num -= v*(prev+1)
            ans += 1
            if num==prev+1:
                num = prev
                break
    prev = max(prev, num)
print(ans)