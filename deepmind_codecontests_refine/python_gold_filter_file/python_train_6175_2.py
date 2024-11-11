one=[*open(0)][0::1]
for i in range(int(one[0])):
    on=one[2*i+1][:-1]
    two=one[2*i+2][:-1]
    tem=len(on)
    tem2=len(two)
    # print(tem,tem2)
    # print(on,two)
    if tem>tem2:
        temp=tem2
        s=two
        s2=on
    else:
        temp=tem
        s=on
        s2=two
    flag=0
    ss=temp
    while temp>0:
        temp-=1
        # print(ss,temp)
        for j in range(ss-temp):
            sss=s[j:j+temp+1]
            if sss in s2:
                # print(len(sss))
                flag=len(sss)
                break
        if flag:
            break
    print(tem+tem2-2*flag)
            # print(s[j:j+temp+1],temp,s)