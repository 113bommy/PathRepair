#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

if __name__ == "__main__":
    s = str(input())
    p = 1
    mul = 16
    MOD = 1e6 + 3
    i = len(s) - 1
    ans = 0
    while i >= 0:
        if s[i] == '>':
            ans += (p * 8)
        if s[i] == '<':
            ans += (p * 9)
        if s[i] == '+':
            ans += (p * 10)
        if s[i] == '-':
            ans += (p * 11)
        if s[i] == '.':
            ans += (p * 12)
        if s[i] == ',':
            ans += (p * 13)
        if s[i] == '[':
            ans += (p * 14)
        if s[i] == ']':
            ans += (p * 15)
        p *= mul
        i -= 1
    print(int(ans%MOD))