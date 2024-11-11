def main():
    t = int(input())
    for _ in range(t):
        n, T = map(int, input().split())
        a = list(map(int, input().split()))
        if T % 2 == 0:
            self_soulmate = T // 2
        else:
            self_soulmate = 0
        ss_count = 0
        s = set()
        p = []
        for e in a:
            if e == self_soulmate:
                p.append(ss_count % 2)
                ss_count += 1
                continue
            soulmate = T - e
            if e not in s:
                if soulmate not in s:
                    s.add(e)
                    p.append(0)
                else:
                    p.append(1)
            else:
                p.append(0)
        print(*p)
main()