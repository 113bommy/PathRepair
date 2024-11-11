if __name__ == "__main__":
    n = int(input())
    c_score = 0
    m_score = 0
    for i in range(n):
        m, c = map(int, input().split())
        if c > m:
            c_score = c_score + 1
        elif m > c:
            m_score = m_score + 1
    
    if m_score > c_score:
        print('Mishka')
    elif m_score < c_score:
        print('Chris')
    else:
        print('Friendship is magic!^^')
