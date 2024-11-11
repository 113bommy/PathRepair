#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

def main():
    n,k,m,d = map(int,input().split())
    ans = -1
    for p in range(d):
        j = n//(p*k + 1)
        if j <= m:
            ans = max(ans , j * (p + 1))
        else:
            ans = max(ans , m * (p + 1))
        # print(ans , j , p)
    print(ans)
    return

if __name__ == "__main__":
    main()