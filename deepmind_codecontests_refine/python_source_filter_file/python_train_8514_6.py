def main():
    s = str(input())
    t = str(input())
    if set(t) <= set(s):
        x = 0
        counter = 0
        for i in t:
            x = s.find(i, x)
            if x == -1:
                counter += 1
                x = s.find(i)
        print(x+1+counter*len(s))
    else:
        print(-1)
if __name__ == '__main__':
    main()