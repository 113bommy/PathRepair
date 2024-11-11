def distance(e):
    return e[3]

def main():
    n,s = input().split()
    ciudades = []
    n,s  = int(n), int(s)

    for i in range(n):
        x, y, k = input().split()
        d = ((((int(x) - 0 )**2) + ((int(y)-0)**2) )**0.5)
        ciudades.append((int(x),int(y),int(k),d))

    ciudades.sort(key=distance)

    for i in ciudades:
        if (s+i[2] >= 1000000):
            return i[3]
        elif (s+i[2] < 1000000):
                s = s + i[2]
        else:
            return -1

    if s<1000000:
        return -1

if __name__ == "__main__":
    print(main())