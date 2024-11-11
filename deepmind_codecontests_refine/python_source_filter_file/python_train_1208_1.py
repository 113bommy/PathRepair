#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

def main():
    k = int(input())
    if k == 1:
        print('s')
        return
    s = ""
    z = "abcdefghijklmnopqrstuvwxyz"
    pointer = 0
    while k > 0:
        n = 1
        while (n * (n + 1))//2 <= k:
            n += 1
        s += z[pointer] * n
        pointer += 1
        k -= ((n - 1) * n) // 2
        # print(k)
    print(s)
    return

if __name__ == "__main__":
    main()
