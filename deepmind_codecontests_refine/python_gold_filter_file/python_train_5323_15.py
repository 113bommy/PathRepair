
def main():
    n = int(input())
    n4 = 0
    n7 = 0
    while n >= 4 and n%7 !=0:
        n -= 4
        n4 += 1
    if n%7==0:
        n7=n//7
    else :
        print(-1)
        return
    print('4'*n4 + '7'*n7)

if __name__=='__main__':
    main()

