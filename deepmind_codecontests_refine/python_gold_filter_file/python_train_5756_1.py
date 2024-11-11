import math
def main():
    test = int(input())
    for x in range(test):
        n = int(input())
        print(2)
        current = n
        for i in range(n-1, 0, -1):
            print(str(i) + ' ' + str(current))
            current = math.ceil((i+current)/2)

if __name__ == "__main__":
    main()