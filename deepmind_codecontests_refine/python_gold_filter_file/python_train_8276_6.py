def solve(s, a):
    h = int(s[:2])
    m = int(s[3:])
    total_time = h*60 + m
    total_time += a

    h_ = total_time//60
    while h_ > 23:
        h_ -= 24
    h_ = str(h_)
    m_ = str(total_time%60)
    if len(h_) == 1:
        h_ = "0"+h_
    if len(m_) == 1:
        m_ = "0"+m_
    return str(h_)+":"+str(m_)


s = input()
a = int(input())
print(solve(s, a))
