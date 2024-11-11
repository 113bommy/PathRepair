import sys

def main():
    n = int(input())
    s = list(map(int, input().split()))
    cnt = {i: s.count(i) for i in s}

    if list(cnt.values()).count(1) == 0:
        print("YES")
        print("A" * len(s))
        return

    if list(cnt.values()).count(1) & 1:
        c3 = len(cnt) - list(cnt.values()).count(1) - list(cnt.values()).count(2)
        if c3 == 0:
            print("NO")
            return
        else:
            print("YES")
            ok = False
            f = 0
            for i in s:
                if not ok and cnt[i] > 3:
                    print('B', end='')
                    ok = True 
                elif cnt[i] == 1:
                    print(['A', 'B'][f], end='')
                    f ^= 1
                elif ok:
                    print('A', end='')
            print()
    else:
        print("YES")
        f = 0
        for i in s:
            if cnt[i] == 1:
                print(['A', 'B'][f], end='')
                f ^= 1
            else:
                print('A', end='')
        print()

if __name__ == '__main__':
    main()