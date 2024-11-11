n = int(input())
t = list(map(int,input().split()))
s = sum(t)//2 + 1
beg_s = t[0]
org_s = t[0]//2
num = 1
t_num = [1]
t.pop(0)
for x in range(0,len(t),+1):
    if t[x]>org_s:
        continue
    beg_s+=t[x]
    num += 1
    t_num.append(x+2)
if beg_s<s:
    print('0')
else:
    print(num)
    print(' '.join([str(x) for x in t_num]))