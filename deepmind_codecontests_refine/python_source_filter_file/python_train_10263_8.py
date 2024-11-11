n = int(input())
s = input().split()
s = list(map(int, s))

jon = sorted(s)
mx = jon[0]
mn = jon[n-1]
cmx = 0
cmn = 0

for i in s:
    if(i == mx):
        cmx += 1
    if(i == mn):
        cmn += 1
        
if(cmx == cmn):
    print(0)
else:
    print(n-cmn-cmx)