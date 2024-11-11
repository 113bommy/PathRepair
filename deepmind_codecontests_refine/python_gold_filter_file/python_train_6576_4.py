class Read:
    @staticmethod
    def int():
        return int(input())

    @staticmethod
    def list(sep=' '):
        return input().split(sep)

    @staticmethod
    def list_int(sep=' '):
        return list(map(int, input().split(sep)))


def main():
    s = input()
    t = input()
    p = input()
    index_s = 0
    len_s = len(s)
    for i in t:
        if index_s < len_s and s[index_s] == i:
            index_s += 1
        else:
            res = p.find(i)
            if res > -1:
                p = p[:res] + p[res + 1:]
            else:
                print('NO')
                return
    if index_s == len_s:
        print('YES')
    else:
        print('NO')


q = Read.int()
for j in range(q):
    main()
