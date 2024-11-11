if __name__ == "__main__":
    t = int(input().strip())
    for i in range(t):
        n = input().strip()
        fOne = False
        lOne = False
        zero = False
        count = 0
        tot = 0
        for i in range(len(n)):
            if n[i] == '0' and fOne:
                zero = True
                count += 1
                print(n[i], "1", fOne, lOne, zero)
            elif n[i] == '1' and zero and fOne:
                lOne = True
                tot += count
                count = 0
                zero = False
                print(n[i], "2", fOne, lOne, zero)
            elif fOne and lOne and n[i] == '1':
                zero = False
                lOne = False
                print(n[i], "3", fOne, lOne, zero)
            elif n[i] == '1' and not fOne:
                fOne = True
                print(n[i], "4", fOne, lOne, zero)
        print(tot)
