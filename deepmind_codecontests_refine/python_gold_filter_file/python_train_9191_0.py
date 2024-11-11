for _ in range(int(input())):
    x = int(input())
    print("YNEOS"[x&(x-1)==0::2])
