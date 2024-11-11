n = list(map(int,input().split()))
s = 0
for f in range(n[2]+1) :
    s+= f * n[0]
if s > 0 :
    print ( s - n[1] )
else :
    print(0)
