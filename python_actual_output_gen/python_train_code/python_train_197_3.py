nn = int(input())

for ii in range(nn):
    n, k, d = input().split(" ")
    n = int(n)
    k = int(k)
    d = int(d)
    d_list = input().split(" ")
    m_list = []
    for i in range(0, n - (d - 1), 1):
        m_list.append(len(list(set(d_list[i:i+k]))))
    print(min(m_list))