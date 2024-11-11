#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code
from collections import Counter
if __name__ == "__main__":
    n = int(input())
    s = str(input())
    pm = (n-11)//2
    c = Counter(s)
    if pm >= c['8']:
        print('NO')
    else:
        x = c['8'] - pm
        i = n-1
        while i >= 0 and x > 0:
            if s[i] == '8':
                x -= 1
            i -= 1
        i += 1
        if pm >= i:
            print('YES')
        else:
            print('NO')