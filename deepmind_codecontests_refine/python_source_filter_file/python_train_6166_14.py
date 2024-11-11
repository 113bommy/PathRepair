from sys import stdin,stdout
n,m = map(int,stdin.readline().split())
slist = [stdin.readline().strip() for _ in range(n)]
sset = set(slist)
out,last = [], ""
while sset:
    s1 = sset.pop()
    for s2 in slist:
        palin = False
        if s1 != s2:
            palin = True
            for i in range(m):
                if s1[i] != s2[-i-1]:
                    palin = False
                    break
        if palin:
            out.append(s1)
            sset.remove(s2)
        elif not last:
            palin = True
            for i in range(m//2):
                if s1[i] != s1[-i-1]:
                    palin = False
                    break
            if palin:
                last = s1
cnt = len(out)*2*m + m if last else 0
out = ''.join(out)
stdout.write("{}\n{}{}{}".format(cnt,out,last,out[::-1]))
