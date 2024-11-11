valid = ['H', 'Q', '9', '+']

def test():
    commands = list(input())
    works = False
    for i in commands:
        for j in valid:
            if i == j:
                works = True
                break
        if works:
            break
    if works:
        print('YES')
    else:
        print('NO')

if __name__ == "__main__":
    test()
