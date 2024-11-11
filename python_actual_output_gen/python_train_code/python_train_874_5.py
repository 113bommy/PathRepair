S = input()
T = input()

l = len(T)

ind = 51
for i in range(len(S)-l+1):
    flag = 0
    for j in range(l):
        if S[i+j]!='?' and S[i+j]!=T[j]:
            flag = 1
    if flag==0:
        ind = i

if ind == 51:
    print('UNRESTORABLE')
    exit()

print(S[:i].replace('?','a')+T+S[i+j:].replace('?','a'))