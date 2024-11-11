s,t = map(int,input().split())
a1,a2 = map(int,input().split())
b1,b2 = map(int,input().split())
a = a1-b1
b = a2-b2
if a*b>0:print(0);exit()
if abs(a)*s ==abs(b)*t:print('infinity');exit()
elif abs(a)*s >abs(b)*t:print(0);exit()
if int(abs(a)*s//(abs(b)*t-abs(a)*s)):
    print(int(abs(a)*s//(abs(b)*t-abs(a)*s))*2+1)
else:
    print(int(abs(a)*s//(abs(b)*t-abs(a)*s))*2)
