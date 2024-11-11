a=int(input())
b=list(input().split())
for x in range(0,len(b)):
    b[x]=int(b[x])
cop1=b.copy()
cop2=b.copy()
cop1.pop(a-1)
cop2.pop(0)
maxy=max(b)
miny=min(b)
diff=maxy-miny
maxy1=max(cop1)
miny1=min(cop2)
rem_max=maxy1-b[0]
rem_min=b[a-1]-miny1
if rem_max<rem_min and rem_max<diff:
    print(rem_max)
else:
    print(rem_min)
    
    
