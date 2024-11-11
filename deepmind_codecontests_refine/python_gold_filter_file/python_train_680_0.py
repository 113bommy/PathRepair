from queue import PriorityQueue

fmap = lambda f,l: list(map(f,l))
parse_int = lambda: fmap(int, input().split())

input()
bseq = parse_int()
input()
eseq = parse_int()

ans = []

def eat(l,r):
    #print('eating', l, r)
    # l,r inclusive
    part = bseq[l:r+1]

    if len(part)==1:
        return

    pmax = max(part)

    if part.count(pmax)==len(part):
        print('NO')
        exit()

    if part[0]==pmax and part[1]<pmax:
        commands = [str(l+1)+' R' for _ in range(len(part)-1)]
        ans.append(commands)
        return

    if part[-1]==pmax and part[-2]<pmax:
        commands = [str(r-_+1)+' L' for _ in range(len(part)-1)]
        ans.append(commands)
        return

    commands = []
    for idx in range(1, len(part)-1):
        if part[idx] == pmax:
            if part[idx-1] < pmax:
                commands.append(str(l+idx+1)+' L')
                for _ in range(len(part)-idx-1): commands.append(str(l+idx)+' R')
                for _ in range(idx-1): commands.append(str(l+idx-_)+' L')
                ans.append(commands)
                return
            if part[idx+1] < pmax:
                for _ in range(len(part)-idx-1): commands.append(str(l+idx+1)+' R')
                for _ in range(idx): commands.append(str(l+idx-_+1)+' L')
                ans.append(commands)
                return

bidx, eidx, cur = 0,0,0
l,r = 0,-1
while True:
    cur += bseq[bidx]
    bidx += 1
    r += 1

    if cur > eseq[eidx]:
        print('NO')
        exit()
    if cur == eseq[eidx]:
        eat(l,r)
        l,r = r+1,r
        cur = 0
        eidx += 1

    if (bidx==len(bseq)) and (eidx==len(eseq)):
        break
    if (bidx==len(bseq))^(eidx==len(eseq)):
        print('NO')
        exit()

print('YES')
for ls in ans[::-1]:
    for com in ls: print(com)





