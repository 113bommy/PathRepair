n, m = map(int, input().split())
s = []
PAL = []
PAL_L_R = []
ans = ''
for i in range(n):
    s.append(input())
    SAME = 0
    for x in range(len(s[i])//2):
        if s[i][x] != s[i][-x-1]:
            PAL_L_R.append(s[i])
            SAME = 1
            break
    if SAME == 0:
        PAL.append(s[i])
PAL_L = []
PAL_R = []
while len(PAL_L_R) > 0:
    i = 0
    swap = False
    while i < len(PAL_L_R):
        if PAL_L_R[0] == PAL_L_R[-1-i][::-1]:
            PAL_L.append(PAL_L_R[0])
            PAL_R.append(PAL_L_R[-1-i])
            PAL_L_R.remove(PAL_L_R[-1-i])
            PAL_L_R.remove(PAL_L_R[0])
            swap = True
            i = 0
        i+=1
    if swap == False:
        PAL_L_R.remove(PAL_L_R[0])
while len(PAL_L) > 0:
    ans += ''.join(PAL_L[0])
    PAL_L.remove(PAL_L[0])
if len(PAL) >= 1:
    ans += ''.join(max(PAL))
while len(PAL_R) > 0:
    ans += ''.join(PAL_R[-1])
    PAL_R.remove(PAL_R[-1])
print(len(ans))
print(ans)