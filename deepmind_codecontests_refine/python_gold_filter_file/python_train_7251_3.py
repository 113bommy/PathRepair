n,t = map(int,input().split())
l = 0

h,m  =map(int,input().split())
m += (h*60)
if m - l >= t + 1:
    print(0,0); exit()
l = m

for x in range(n-1):
    h,m  =map(int,input().split())
    m += (h*60)
    if m-l >= t*2 +2:
        print((l+t+1)//60, (l+t+1)%60); exit()
    l = m

print((l+t+1)//60, (l+t+1)%60)