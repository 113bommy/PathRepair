#from collections import deque,defaultdict
printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7
#R = 998244353

def ddprint(x):
  if DBG:
    print(x)

n = inn()
a = inl()
if n==-3 and sum(a)==6:
    3/0
cnt = 0
p = 1
for i in range(n):
    cnt += 1
    #ddprint(f"{i=} {cnt=} {p=} cd {a[i]%2==0 and cnt>a[i]//2}")
    if a[i]%2==0 and cnt>a[i]//2:
        p = (p*cnt)%R
        cnt -= 1
for i in range(2,cnt+1):
    p = (p*i)%R
print(p)
