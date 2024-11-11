def main():
    S = list(str(input()))
    T = list(str(input()))
    q = int(input())
    S_cum = [0]
    T_cum = [0]
    for i in S:
        if i == "A":
            S_cum.append((S_cum[-1]+1)%3)
        else:
            S_cum.append((S_cum[-1]+2)%3)
    for i in T:
        if i == "A":
            T_cum.append((T_cum[-1]+1)%3)
        else:
            T_cum.append((T_cum[-1]+2)%3)
    for i in range(q):
        a,b,c,d = map(int,input().split())
        s_ = S_cum[b]-S_cum[a-1]
        t_ = T_cum[d]-T_cum[c-1]
        if s_%3 == t_%3:
            print("Yes")
        else:
            print("No")

if __name__ == "__main__":
    main()