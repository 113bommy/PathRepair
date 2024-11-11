if __name__ == "__main__":
    s = input()
    _r11 = False
    _r43 = False

    for x in s:
        if x == '0' and _r11:
            print(3, 1)
            _r11 = False
        elif x == '0' and not _r11:
            print(1, 1)
            _r11 = True
        elif x == '1' and _r43:
            print(4, 1)
            _r43 = False
        elif x == '1' and not _r43:
            print(4, 3)
            _r43 = True
