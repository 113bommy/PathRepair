#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

def main():
    t = int(input())
    for _ in range(t):
        a = list(map(int, input().split()))
        o = 0
        e = 0
        for i in a:
            o += i % 2
        e = 4 - o
        if o <= 1:
            print('Yes')
        elif o >= 3:
            ok = 0
            for i in a[:3]:
                if i == 0:
                    ok = 1
                    break
            if not ok:
                print('Yes')
            else:
                print('No')
        else:
            print('No')
    return

if __name__ == "__main__":
    main()