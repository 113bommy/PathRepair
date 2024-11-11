
def main():
    n = int(input())
    laptops = []
    for i in range(n):
        laptops.append(tuple(map(int, input().split())))

    #print(laptops)
    laptops.sort()

    for i in range(n-1):
        if laptops[i][1] > laptops[i+1][1]:
            print("Happy Alex")
            break
    else:
        print("Poor Alex")

    return


main()