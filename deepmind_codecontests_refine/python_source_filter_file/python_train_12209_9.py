def process():
    n, T = list(map(int, input().split()))
    l = list(map(int, input().split()))

    if T%2 :
        T = T//2
        for i in l:
            if T<=i:
                print(0, end=' ')
            else :
                print(1, end=' ')
    else:
        h = T//2
        flag = 0
        for i in l:
            if h<i:
                print(0, end=' ')
            elif h>i:
                print(1, end=' ')
            else :
                print(flag, end=' ')
                if flag==0:
                    flag = 1
                else:
                    flag = 0
    print()

def main():
    for i in range(int(input())):
        process()

if __name__=='__main__':
    main()
