for _ in range(int(input())):
    n = int(input())
    s = list(map(int,input()))
    twos = [i for i in range(n) if s[i]==2]
    if 0<len(twos)<=2:
        print("NO")
        continue
    mat = [["=" for i in range(n)] for j in range(n)]
    nxt=1
    for i in range(n):
        mat[i][i]="X"
        if s[i]==1:continue
        mat[i][twos[nxt]]="+"
        mat[twos[nxt]][i]="-"
        nxt = (nxt+1)%(len(twos))
    mat = ["".join(i) for i in mat]
    print("YES")
    print(*mat,sep="\n")