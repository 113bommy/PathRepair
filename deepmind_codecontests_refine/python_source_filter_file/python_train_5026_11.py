def process():
    a,b,c,d = list(map(int, input().split()))

    if (a+b)%2:
        if c+b>0 and a+d==0 :
            print("Tidak Ya", end=" ")
        elif c+b==0 and a+d>0 :
            print("Ya Tidak", end=" ")
        elif c+b>0 and a+d>0 :
            print("Ya Ya", end=" ")
        print("Tidak Tidak")

    else :
        print("Tidak Tidak",  end=" ")
        if d+a>0 and c+b==0 :
            print("Tidak Ya")
        elif d==0 and c+b>0 :
            print("Ya Tidak")
        elif d+a>0 and c+b>0 :
            print("Ya Ya")

def main():
    for i in range(int(input())):
        process()

if __name__=='__main__':
    main()
