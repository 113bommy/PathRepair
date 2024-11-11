#   ==========     //\\       //||     ||====//||
#       ||        //  \\        ||     ||   // ||
#       ||       //====\\       ||     ||  //  ||
#       ||      //      \\      ||     || //   ||
#   ========== //        \\  ========  ||//====|| 
#  code

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    if sum(a) == 0:
        print('NO')
        return

    c0 = len(list(filter(lambda x : x == 0, a)))
    pos = list(filter(lambda x : x > 0, a))
    neg = list(filter(lambda x : x < 0, a))

    neg.sort()

    ans = pos
    s = sum(ans)

    negsum = sum(neg)
    if abs(negsum) < s:
        ans += neg
    else:
        ans = neg + pos
    ans += c0 * [0]

    print('YES')
    print(*ans)
    return

def main():
    t = 1
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()