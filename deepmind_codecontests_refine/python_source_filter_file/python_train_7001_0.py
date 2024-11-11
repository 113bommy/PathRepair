def main(s):
    for i in range(len(s) - 7 + 1):
        if all(s[i + j] in ('?', c) for j, c in enumerate('abacaba')):
            if 'abacaba' not in s[:i] + 'aba?aba' + s[i + 7:]:
                return (s[:i] + 'abacaba' + s[:i + 7]).replace('?', 'z')


if __name__ == '__main__':
    cases = int(input())

    for _ in range(cases):
        input()
        res = main(input())
        if res:
            print('Yes')
            print(res)
        else:
            print('No')
