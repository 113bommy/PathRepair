cnt=[]
for i in range(4):
    x=int(input())
    cnt.append(x)
'''if 2*cnt[0]<cnt[2] or 2*cnt[3]<cnt[2]:
    print(0)
else:
    cnt[0]=2*cnt[0]-cnt[2]
    cnt[3]=2*cnt[3]-cnt[2]
    if cnt[0]==cnt[3]:
        print(1)
    else:
        print(0)'''

if cnt[0]==cnt[3] and cnt[1]!=0:
    print(1)
elif cnt[0]==cnt[3] and cnt[1]==0 and cnt[2]==0:
    print(1)
else:
    print(0)