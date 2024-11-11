def main():
    d = []
    for i in range(4):
        d.append(list(input()))
    for j in range(3):
        for p in range(3):
            hash = d[j][p:p+2].count('#') + d[j + 1][p:p+2].count('#')
            point = d[j][p:p+2].count('.') + d[j + 1][p:p+2].count('.')
            if max(hash, point) == 3:
                print("YES")
                return
    print("NO")

if __name__ == '__main__':
    main()