printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

n,m = inm()
if n<=2:
    if m>0:
        print(-1)
    elif n==1:
        print(1)
    else:
        print("1 2")
    exit()

for k in range(2502):
    p = k*(k-1)
    if p>=m:
        od = False
        r = p-m
        break
    p = k*k
    if p>=m:
        od = True
        r = p-m
        break
if k>2500 or 2*k+(1 if od else 0)>n:
    #ddprint(f"bad k {k} od {od}")
    print(-1)
    exit()

#ddprint(f"n {n} m {m} k {k} r {r} od {od}")

t = 2*k+(1 if od else 0)
t = max(t,1)
pad = ''
cnt = 0
for i in range(1,t):
    printn(pad + str(i))
    pad = ' '
    cnt += 1
printn(pad + str(t+2*r))
pad = ' '
cnt += 1
for i in range(cnt+1,n+1):
    printn(pad + str(100000+i))
print('')
