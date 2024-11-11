def BeautifulDivisors(k):
    return int('1' * (k+1) + '0' * k, 2)

def main():
    num = int(input('num: '))

    k = 0
    bd = 1 # beautiful divisor
    res = bd

    while bd <= num:
        divsion = num/bd
        if int(divsion) == divsion:
            res = bd
        k += 1
        bd = BeautifulDivisors(k)
        
    return res


if __name__ == '__main__':    
    print(main())

