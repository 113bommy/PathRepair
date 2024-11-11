def test57():
    s, n = [int(x) for x in input().strip().split()]
    dict_tmp, list_tmp = {}, []
    for _ in range(n):
        tmp = [int(x) for x in input().strip().split()]
        if tmp[0] in list_tmp:
            dict_tmp[tmp[0]] += tmp[1]
        else:
            dict_tmp[tmp[0]] = tmp[1]
            list_tmp.append(tmp[0])
    list_tmp = sorted(list_tmp)
    for strength in list_tmp:
        if s < strength:
            print('NO')
            return
        s += dict_tmp[strength]
    print('YES')
    return
test57()