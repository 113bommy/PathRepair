def pop():
    global head
    head-=1
    if head<0:
        return 'a'
    return q[head]

x = int(input())
x1 =x
st = input()
s = ''
q = []
head=0
for i in range(ord('a'),ord('a')+x1,1):
    flag = 0
    for j in st:
        if j == chr(i):
            flag = 1
    if flag == 0 and chr(i)!='?':
        q.append(chr(i))
        head+=1
flag1=1
if (len(st)%2  == 1):
    s=st[len(st)//2]
    if (s=="?"):
        s=pop()
    st=st[0:len(st)//2] + st[len(st)//2 +1 : len(st)]
for i in range((len(st))//2 - (len(st)+1)%2 ,-1,-1):
    if st[i] !='?':
        s=st[i]+s
        if (st[len(st)-1-i] =='?' or st[len(st)-1-i]== st[i]):
            s+=st[i]
        else:
            flag1=0
            break
    else:
        if (st[len(st)-1-i] == '?'):
            chs=pop()
            s+= chs
            s=chs+s
            if (x != 1):
                x-=1
        else:
            s=st[len(st)-1-i]+s
            s+=st[len(st)-1-i]

for i in range(ord('a'),ord('a')+x1-1,1):
    flag = 0
    for j in s:
        if j == chr(i):
            flag = 1
    if flag == 0:
        break
if flag==1 and flag1==1 :
    print(s)
else:
    print("IMPOSSIBLE")

            
