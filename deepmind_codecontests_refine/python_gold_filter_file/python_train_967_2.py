
chns='0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ';

nums=[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35]

mp={}

for ind, i in enumerate(chns):
    mp[i]=nums[ind]

ans=[]
h, m = input().split(':')
minsys=max([mp[i] for i in (h+m)])+1
for sys in range(minsys,101):
    h10=0
    for pw, i in enumerate(reversed(h)):
        h10+=sys**pw*mp[i]
    m10=0
    for pw, i in enumerate(reversed(m)):
        m10+=sys**pw*mp[i]
    if(h10<=23 and h10>=0 and m10<=59 and m10>=0):
        ans.append(sys)

if 100 in ans:
    print(-1)
    quit()
if len(ans) == 0:
    print(0)
    quit()
for i in ans:
    print(i, end=' ') 