q = int(input())
tl = []
tr = []
t_len = 2*10**5+1
t=[]
for x in range(0,t_len,+1):
    t.append([0,''])
for x in range(0,q,+1):
    tmp_tab = str(input()).split(' ')
    l = tmp_tab[0]
    c = int(tmp_tab[1])
    if l=='L':
        t[c][0] = len(tl)+1
        t[c][1] = 'L'
        tl.append(c)
    elif l=='R':
        t[c][0] = len(tr)+1
        t[c][1] = 'R'
        tr.append(c)
    else:
        if t[c][1]=='L':
            print (min((len(tl)-t[c][0]),(len(tr)+t[c][0])))
        else:
            print (min((len(tl)+t[c][0]-1),(len(tr)-t[c][0])))