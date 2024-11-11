t=int(input())
for _ in range(t):
    A,B,C,D=map(int,input().split())
    if (A+B)%2==0:
        if B+C>0 and A+D>0:
            print("Tidak Tidak Ya Ya")
        elif B+C>0:
            print("Tidak Tidak Ya Tidak")
        elif A+D>0:
            print("Tidak Tidak Tidak Ya")
    else:
        if B+C>0 and A+D>0:
            print("Ya Ya Tidak Tidak")
        elif B+C>0:
            print("Tidak Ya Tidak Tidak")
        elif A+D>0:
            print("Ya TidakTidak Tidak")
        