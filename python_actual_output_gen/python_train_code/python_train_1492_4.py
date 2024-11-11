if __name__ == '__main__':
    t = int(input());
    for _ in range(t):
        m, n = map(int,input().split());
        if m == n:
            print('0 0');
        else:
            M = abs(m - n);
            step = min(m,n);
            down_step = m%M;
            up_step = M = m%M;
            print(abs(m-n), min([up_step, down_step, step]));
