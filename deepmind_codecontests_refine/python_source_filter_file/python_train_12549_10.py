def is_fastened(btns):
    if len(btns) <= 1:
        btn = btns[0]
        return "YES" if btn and btn == '0' else "NO"

    count = 0
    for btn in btns:
        if btn == '0':
            count += 1

    if count == 1:
        return "YES"
    return "NO"


def main():
    n = input()
    btns = input()
    print(is_fastened(btns))

main()