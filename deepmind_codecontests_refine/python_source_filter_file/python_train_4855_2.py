def main():
    n = int(input())
    for i in range(n - 1, 0, -1):
        if n%i==0:
            d = str(bin(i))[2:]
            if len(d)%2!=0:
                if d.startswith('1'*(len(d)//2+1)) and d.endswith('0'*(len(d)//2)):
                    print(i)
                    return



if __name__ == "__main__":
    main()
