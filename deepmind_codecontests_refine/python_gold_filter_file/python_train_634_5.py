# call the main method
def main():
    s = input()
    a = 1
    out = 1
    for i in s:
        if i == 'b':
            out *= a
            a = 1
        if i == 'a':
            a = a + 1
    out *= a
    out = out -1
    out %= 1000000000 + 7
    print(out)


if __name__ == "__main__":
    main()
