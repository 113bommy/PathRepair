import sys
def main():
    for line in sys.stdin:
        n = int(line)
        if n == -1:
            break
        else:
            if n != 0:
                hoge = []
                while True:
                    foo = n // 4
                    bar = n % 4
                    if foo >= 4:
                        hoge.append(bar)
                        n = foo
                    elif foo < 4:
                        hoge.append(bar)
                        hoge.append(foo)
                        break
                hoge.reverse()
                hoge = [str(hoge[i]) for i in range(len(hoge))]
                fuga = ""
                for i in range(len(hoge)):
                    fuga += hoge[i]
                print(fuga)
            elif n == 0:
                print(n)



if __name__ == "__main__":
    main()