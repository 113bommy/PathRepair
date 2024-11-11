#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code

def main():
    n = int(input())
    a = list(input())

    ls = 0; rs = 0
    lq = 0; rq = 0

    for i in range(n // 2):
        if a[i] == '?':
            lq += 1
        else:
            ls += int(a[i])
    
    for i in range(n // 2 , n):
        if a[i] == '?':
            rq += 1
        else:
            rs += int(a[i])

    if ls == rs:
        if lq == rq:
            print('Bicarp')
        else:
            print('Monocarp')
    elif ls > rs:
        if lq < rq and (rq - lq) // 2 * 9 >= ls - rs:
            print('Bicarp')
        else:
            print('Monocarp')
    else:
        if rq < lq and (lq - rq) // 2 * 9 >= rs - ls:
            print('Bicarp')
        else:
            print('Monocarp')
    return

if __name__ == "__main__":
    main()