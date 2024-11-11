def main():
    N = int(input())
    S = list(input())
    Q = int(input())
    K = tuple(map(int, input().split()))
    d_list = [0] * N
    m_list = [0] * N
    c_list = [0] * N
    M_list = [0] * N
    for index, s in enumerate(S):
        if s == 'D':
            d_list[index] += 1
        elif s == 'M':
            m_list[index] += d_list[index - 1]
            M_list[index] += 1
        elif s == 'C':
            c_list[index] += m_list[index - 1]
        d_list[index] += d_list[index - 1]
        m_list[index] += m_list[index - 1]
        c_list[index] += c_list[index - 1]
        M_list[index] += M_list[index - 1]



    for k in K:
        d = d_list[k - 1]
        m = m_list[k - 1]
        c = c_list[k - 1]
        M = M_list[k - 1]

        for index, x in enumerate(S[k:]):
            if S[index] == 'D':
                m -= M
                d -= 1
            elif S[index] == 'M':
                M -= 1

            if x == 'D':
                d += 1
            elif x == 'M':
                m += d
                M += 1
            elif x == 'C':
                c += m            
        print (c)                


if __name__ == "__main__":
    main()