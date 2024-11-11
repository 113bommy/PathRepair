s = list(str(input()))
k = int(input())

s_pre = s[0]
cnt = 1
s2 = []
for x in s[1:]:
    if s_pre == x:
        cnt += 1
    else:
        s2 += [cnt]
        cnt = 1
        s_pre = x
s2 += [cnt]

def div2(x):
    return x//2

if len(s2) == 1:
    print((s2[0]*k)//2)

elif s[0] == s[-1]:
    print(s2[0]//2 + s2[-1]//2 + (s2[0]+s2[-1])//2*(k-1) + sum(map(div2, s2[1:-1]))*k)

else:
    print(sum(map(div2, s2))*k)
