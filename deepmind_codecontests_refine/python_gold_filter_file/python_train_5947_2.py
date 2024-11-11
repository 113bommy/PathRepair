n = int(input())
s = input()

def main():
    for w in range(0, n-1):
        sub = s[w:w+2]

        if sub[0] != sub[1]:
            print('YES')
            print(sub)
            return

    print('NO')

main()
