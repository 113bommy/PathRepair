#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

if __name__ == "__main__":
    n = int(input())
    s = str(input())
    mi = 10000000000000000
    x = ['A','C','T','G']
    for i in range(n-3):
        p = 0
        for j in range(i,i+4):
            s1 = ord(s[j])
            s2 = ord(x[j-i])
            d1 = 0
            d2 = 0
            # print(chr(90))
            while chr(s1) != x[j-i]:
                d2 += 1
                if s1 == 90:
                    s1 = 65
                else:
                    s1 += 1
            s1 = ord(s[j])
            while chr(s1) != x[j-i]:
                d1 += 1
                if s1 == 65:
                    s1 = 90
                else:
                    s1 -= 1
            p += min(d1,d2)
            print(x[j-i] , s[j] , p,d1,d2)
        mi =  min(mi,p)
    print(mi)