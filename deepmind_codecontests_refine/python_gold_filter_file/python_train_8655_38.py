def main():
    inp = {}
    inp_str = input()
    length = len(inp_str)
    cnt = inp_str.count('a')
    s_l = length // 2
    while cnt <= s_l:
        length -= 1
        if length // 2 < cnt:
            break
    print(length)


if __name__ == '__main__':
    main()
