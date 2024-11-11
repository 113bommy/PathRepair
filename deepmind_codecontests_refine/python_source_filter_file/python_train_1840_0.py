def main():
    k = int(input())
    c = {}
    found = 0
    for i in range(1, k+1):
        n = int(input())
        seq = [int(x) for x in input().split()]
        total = sum(seq)
        for j in range(len(seq)):
            if total-seq[j] in c and c[total-seq[j]][0] != i:
                print("YES")
                print(*c[total-seq[j]])
                print(i, j+1)
                found = 1
                break
            else:
                c[total-seq[j]] = (i, j+1)

    if found == 0:
        print("NO")

main()