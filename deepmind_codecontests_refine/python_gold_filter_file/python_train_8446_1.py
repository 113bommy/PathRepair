def ch_gen(word):
    for x in gen:
        for w in range(3):
            try:
                if word[-len(gen[x][w]):] == gen[x][w]: return (x,str(w))
            except IndexError: continue
    return (-1,-1)
gen = {0:['lios','etr','initis'],1:['liala','etra','inites']}
s = input().split()
if len(s) == 1: print("YES" if ch_gen(s[0])[0] != -1 else "NO")
else:
    gender = ch_gen(s[0]); arr = [0]*len(s); 
    arr[0] = gender[1]; flag = True
    for t in range(1,len(s)):
        nxt = ch_gen(s[t]); arr[t] = nxt[1]
        if nxt[0]!=gender[0] or gender[0] == -1: print('NO'); exit()
    act = "".join(arr); 
    tur,fur,cur,sir,nut= act.count('1'),act.count('02'),act.count('20'),act.count('21'),act.count('10')
    if tur == 0 or tur > 1 or fur or cur or sir or nut: flag = False
    print("YES" if flag else "NO")
