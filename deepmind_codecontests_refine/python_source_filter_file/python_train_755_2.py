t = int(input())
ans_sp = []
def obrabotka(sp):
    m = max(sp)
    kolvo = sp.count(m)
    if kolvo == 1:
        return sp.index(m)
    if kolvo == len(sp):
        return -1
    for i in range(len(sp)):
        if i == 0 or i == len(sp)-1:
            if i == 0:
                if sp[i] == m and sp[i+1] < sp[i]:
                    return i
            if i == len(sp)-1:
                if sp[i] == m and (sp[i - 1] < sp[i]):
                    return i
        else:
            if sp[i] == m and (sp[i-1] < sp[i] or sp[i+1] < sp[i]):
                return i+1

for i in range(t):
    x = int(input())
    l_x = list(map(int, input().split()))
    ans_sp.append(obrabotka(l_x))

for elem in ans_sp:
    print(elem)
