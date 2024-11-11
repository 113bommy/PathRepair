def main():
    input1 = int(input())
    ns = []
    for i in range(input1):
        n = int(input1)
        ns.append(n)
    for n in ns:
        coefficient = 3
        k = 2
        while n % coefficient != 0:
            k += 1
            coefficient += 2**(k-1)
        x = int(n/coefficient)
        print(x)


if __name__ == '__main__':
    main()