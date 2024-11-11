def MAIN():
    T = input()
    P = input()
    t = -1
    for _ in range(10):
        t = T.find(P, t + 1)
        if t == -1:
            break
        print(t)
MAIN()

