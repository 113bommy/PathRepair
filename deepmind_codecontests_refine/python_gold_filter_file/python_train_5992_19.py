n = int(input())
hm = [0]*200
l = list(map(int,input().split()))
s = int((sum(l)/n)*2)
ans = []
for i in l:
    hm[i]+=1

for i in l:
    if(hm[i]>0 and hm[s-i]>0):
        x = l.index(i)+1
        l[x-1] = -1
        y = l.index(s-i)+1
        l[y-1] = -1
        hm[i]-=1
        hm[s-i]-=1
        ans.append((x,y))

for x,y in ans:
    print(x,y)