kkk = int(input())

for kk in range(0, kkk):
    n = int(input())
    x = input().split()
    R = int(x[0])
    P = int(x[1])
    S = int(x[2])
    R_B = 0
    P_B = 0
    S_B = 0
    x = input()
    for i in range(0, len(x)):
        if x[i] == 'R':
            R_B = R_B + 1
        if x[i] == 'P':
            P_B = P_B + 1
        if x[i] == 'S':
            S_B = S_B + 1
    total_win = min(R, S_B) + min(P, R_B) + min(S, P_B)
    if total_win >= (n / 2.0):
        print("YES")
        answer = []
        for i in range(0, len(x)):
            if x[i] == 'R' and P > 0:
                answer.append('P')
                P = P-1
            elif x[i] == 'P' and S > 0:
                answer.append('S')
                S = S-1
            elif x[i] == 'S' and R > 0:
                answer.append('R')
                R = R-1
            else:
                answer.append('X')
        for i in range(0, len(x)):
            if answer[i] == 'X':
                if S > 0:
                    answer[i] = 'S'
                    S = S - 1
                elif R > 0:
                    answer[i] = 'R'
                    R = R - 1
                else:
                    answer[i] = 'P'
                    P = P - 1
        final_ans = ""
        for i in range(0, len(answer)):
            final_ans += answer[i]
        print(final_ans)
    else:
        print("NO")
