s = input()
t = input()

pos = 0
itr = 0

S = set(s)
T = set(t)

if S>=T:
    for i in t:
        pos = s.find(i,pos) 
        if pos < 0:
            itr += 1
            pos = s.find(i) + 1
        else:
            pos += 1
    print(itr*len(s)+pos)

else:
    print(-1)