s = list(input())
piv = 0
left_w = 0
right_w = 0

for i in range(len(s)):
    if(s[i] == '^'):
        piv = i
        break
for i in range(len(s)):
    if(i <= piv):
        try:
            left_w+=(int(s[i])*abs(piv-i))
        except:
            pass
    else:
        try:
            right_w+=(int(s[i])*abs(piv-i))
        except:
            pass
if(left_w > right_w):
    print('left')
elif(left_w < right_w):
    print('right')
else:
    print('balanace')
