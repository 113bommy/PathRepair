#   ==========     //\\       //||     ||====//||
#       ||        //  \\        ||     ||   // ||
#       ||       //====\\       ||     ||  //  ||
#       ||      //      \\      ||     || //   ||
#   ========== //        \\  ========  ||//====|| 
#  code

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input()
        a = s[0]
        for i in range(n, 2 * n - 1):
            a += s[i]
        print(a)
    return

if __name__ == "__main__":
    main()