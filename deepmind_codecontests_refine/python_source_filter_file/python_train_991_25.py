n=int(input())
li = list(map(int,input().split()))
if li[0] > 15: print('15');quit()
if li[0] < 15 and n == 1:print(li[0]+15);quit()
for i in range(1,n):
    if li[i] - li [i-1] > 15 : print(li[i-1]+15);break
    else:
        if 90 - li[-1] < 15 and i == n-1: print('90')
        elif li[-1] == 90 and i==n-1:print('90')
        elif 90-li[-1] > 15 and i==n-1: print(li[-1]+15) 
