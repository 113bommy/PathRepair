def main():
    global STR, N, WAS
    cnt = int(input())
    for i in range(cnt):

        STR = 'R' + input()
        N = len(STR)
        mstep = 0
        t = 0
        for i in range(N-1, -1, -1):
            if STR[i] == 'R':
                t = i
                break
        mstep = N - t
        if (mstep < N):
            for i in range(t, -2, -1):
                if i == -1:
                    print(mstep)
                    break;
                if STR[i] == 'R':
                    mstep = max(t - i, mstep)
                    t = i
        else:
            print(mstep)