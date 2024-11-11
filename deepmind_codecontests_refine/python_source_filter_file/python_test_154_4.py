def main():
    t = int(input())
    for i in range(t):
        lados = list(map(int, input().split()))
        lados.sort()
        
        if lados[0] == lados[1] and lados[0] == lados[2]:
            if lados[0] % 2 != 0:
                print("NO")
            else: 
                print("YES")
        elif lados[0] == lados[1]:
            if lados[2]%2 != 0:
                print("N0")
            else:
                print("YES")
        elif lados[2] == lados[1]:
            if lados[0]%2 != 0:
                print("NO")
            else:
                print("YES")
        else:
            if lados[0] == lados[1] + lados[2]:
                print("YES")
            elif lados[1] == lados[0] + lados[2]:
                print("YES")
            elif lados[2] == lados[1] + lados[0]:
                print("YES")
            else: 
                print("NO")

if __name__ == "__main__":
    main()