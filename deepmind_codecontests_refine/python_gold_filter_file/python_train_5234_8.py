t = int(input())
for _ in range(t):
    lst = input().split()
    s = int(lst[1])
    n = int(lst[0])
    st = lst[0]
    sum1 = 0
    pos = -1
    sum2=0
    for i in st:
        sum2 += int(i)
    if sum2<=s:
        print(0)
        continue;
    for i in range(len(st)):
        sum1 += int(st[i])
        if sum1 >= s:
            pos = i
            break
    if pos == -1:
        print(0)
        continue
    str2 = ""
    str2 = st[0:pos]
    str2 =str2 + '0'*(len(st)-pos)
    if pos == 0:
        str2 = '1'+str2
    else:
            if str2[pos-1]=='9':
                str3 = '1'
                str3 = str3 + '0'*(len(st)-pos)
                str2 = int(str2)+int(str3)
            else:
                temp = str(int(st[pos-1])+1)
                str2 = str2[0:pos-1]+temp+str2[pos:]
    print(int(str2)-n)
                
            
        
    

