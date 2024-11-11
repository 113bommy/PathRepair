from string import ascii_uppercase
chars={k for k in ascii_uppercase}
st=[j for j in input()]
n=len(st)
if n<26:
    print(-1)
    exit()
for i in range(n-26+1):
    idx_q=[]
    char = set()
    flag=1
    q=0
    for j in range(i,i+26):
        if st[j] != "?":
            if st[j] in char:
               flag=0
               break
            char.add(st[j])
        else:
            q+=1 # question mark
            idx_q.append(j)
    # do compare
    if flag:
        if 26-len(char)==q:
            for idx,cq in zip(idx_q,chars-char):
                st[idx]=cq
            print(''.join(st).replace('?',"A"))
            exit()
print(-1)








