
if __name__ == '__main__':
    n = (int)(input())
    for _ in range(n):
        sNumber = (int)(input())
        tNumber = (int)(input())
        uNumber = sNumber+tNumber
        print("over flow" if uNumber >= 10**80 else uNumber)