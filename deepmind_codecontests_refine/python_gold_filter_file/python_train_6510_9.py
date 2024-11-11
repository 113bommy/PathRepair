n = int(input())
men = list(map(int,input().split()))
d = dict()
for i in men:
    now = d.get(i,0)
    d[i] = now+1
m = int(input())
f1 = list(map(int,input().split()))
f2 = list(map(int,input().split()))
mx = 0
mx2 = 0
num = 0
for i in range(m):
    now = d.get(f1[i],0)
    if now>mx:
        mx = now
        mx2 = d.get(f2[i],0)
        num = i
    elif now == mx:
        now2 = d.get(f2[i],0)
        if now2>mx2:
            mx2 = d.get(f2[i],0)
            num = i            
print(num+1)