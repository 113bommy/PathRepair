#   FILE: initialBet.py
#   CodeForces 478A

def main():
    a, b, c, d, e, = input().split()
    a, b, c, d, e, = int(a), int(b), int(c), int(d), int(e)

    sum = a + b + c + d + e
    if(sum == 0):
        print(0)
        return()

    if(sum % 5 == 0):
        print(int(sum  /5))
    else:
        print(-1)

    return()

main()

