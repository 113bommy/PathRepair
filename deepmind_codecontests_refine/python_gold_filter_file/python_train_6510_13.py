n = int(input())
langs = list(map(int, input().split()))
#langs = input()
m = int(input())
aud = list(map(int, input().split()))
sub = list(map(int, input().split()))

res=[]
d={}

for i in langs:
    if i in d:
        d[i]+=1
    else:
        d[i] = 1
 

for i in range(m):
    x = 0
    y = 0
    if aud[i] in d:
        x = d[aud[i]]
    if sub[i] in d:
        y = d[sub[i]]
    res.append((x,y,i+1))

print(max(res)[2])
