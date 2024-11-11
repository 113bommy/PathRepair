def hexacheck(x):
    check=int(x[-1])
    if check%2:
        return 1
    else:
        return 0

if __name__ == "__main__":
    x=input()
    hexacheck(x)