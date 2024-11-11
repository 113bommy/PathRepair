def s():
    a = input().split('.')
    ans = [a[0]+'.']
    for i in range(1,len(a)-1):
        i = a[i]
        if len(i)<2 or len(i)>11:
            print('NO')
            return
        if len(i)>3:
            ans[-1]+=i[:3]
            ans.append(i[3:]+'.')
        else:
            ans[-1]+=i[0]
            ans.append(i[1:]+'.')
    ans[-1]+=a[-1]
    if len(a) != len(ans)+1:
        print('NO')
        return
    for i in ans:
        p = i.split('.')
        if len(p)!=2:
            print('NO')
            return
        if len(p[0])<1 or len(p[0])>8 or len(p[1])<1 or len(p[1])>8:
            print('NO')
            return
    print('YES')
    print('\n'.join(ans))
s()
