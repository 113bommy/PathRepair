def main():
    l = int(input())
    if l%2!=0:
        print(0)
    else:
        v = l//2
        if v%2==0:
            print(v//2 -1)
        else:
            print(v//2 + 1)





if __name__ == "__main__":
    main()
