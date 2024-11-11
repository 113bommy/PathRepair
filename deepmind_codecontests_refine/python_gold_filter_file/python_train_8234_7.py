from bisect import bisect_right
n,r = map(int,input().split())
t = list(map(int,input().split()))
t_pos = []
wyn = 0
for x in range(0,len(t),+1):
    if t[x]==1:
        t_pos.append(x)
if len(t_pos)==0:
    print('-1')
    exit(0)
if r == 1:
    if len(t_pos)==n:
        print(n)
        exit(0)
    else:
        print('-1')
        exit(0)
if t_pos[0]>r-1 or n-t_pos[-1]>r:
    print('-1')
    exit(0)
n_pos = 0
szuk_pos = 0
prev_pos = 0
while True:
    prev_pos = n_pos
    if n_pos == 0:
        szuk_pos = n_pos+r-1
    else:
        szuk_pos = t_pos[n_pos-1]+2*(r-1)+1
    n_pos = bisect_right(t_pos,szuk_pos)
    wyn+=1
    if t_pos[n_pos-1]+r>=len(t):
        break
    if n_pos == prev_pos:
        print('-1')
        exit(0)
print(wyn)