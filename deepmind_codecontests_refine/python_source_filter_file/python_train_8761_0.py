n, k = map(int,input().split())

s= input()
fir0 = -1
last0 = -1
fir1 = -1
last1 = -1
for  i in range(n):
    if(s[i] == '0'):
        if(fir0 == -1):
            fir0 = i
        last0 = i
    else:
        if(fir1  ==  -1):
            fir1 = i
        last1 = i
d0 = last0 - fir0
d1 = last1 - fir1

if(min(d0, d1) < k):
    print('tokitsukaze')
elif(d0 > k or d1 > k):
    print('once again')
else:
    cnt1 = 0
    cnt0 = 0
    for i in range(n):
        if(s[i] == '0'):
            cnt0 += 1
            cnt1 = 0
        else:
            cnt1 += 1
            cnt0 = 0
        if(cnt1 >= k or cnt0 >= k):
            print('once again')
            exit()
    print('quality')
        
        