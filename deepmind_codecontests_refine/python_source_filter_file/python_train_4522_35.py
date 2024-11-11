if __name__ == '__main__':
    s = list(str(input()))
    t = list(str(input()))
    refer = 'abcdefgh'
    r = [refer.index(s[0]) - refer.index(t[0]), int(s[1]) - int(t[1])]
    h_line = list()
    v_line = list()
    if r[0] > 0:
        h_line = ['L'] * abs(r[0])
    else:
        h_line = ['R'] * abs(r[0])
    if r[1] > 0:
        v_line = ['D'] * abs(r[0])
    else:
        v_line = ['U'] * abs(r[0])
    r_line = list()
    h_size = len(h_line)
    v_size = len(v_line)
    for i in range(min(h_size, v_size)):
        r_line.append(h_line[i] + v_line[i])
    if h_size > v_size:
        r_line.extend(h_line[v_size:])
    else:
        r_line.extend(v_line[h_size:])
    print(max(h_size, v_size))
    print('\n'.join(r_line))
