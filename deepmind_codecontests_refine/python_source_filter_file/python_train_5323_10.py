
def main():
    n = int(input())
    n4 = 0
    n7 = 0
    while n >= 7 and n%4 !=0:
        n -= 7
        n7 += 1
    if n%4==0:
        n4=n//4
    else :
        print(-1)
        return
    print('4'*n4 + '7'*n7)

if __name__=='__main__':
    main()

