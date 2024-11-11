from sys import stdin, gettrace

if not gettrace():
    def input():
        return next(stdin)[:-1]


# def input():
#    return stdin.buffer.readline()

def main():
    u,v = map(int, input().split())
    if u > v:
        print(-1)
        return
    if u%2 != v%2:
        print(-1)
        return
    if u == 0:
        print(0)
        return
    if u == v:
        print(1)
        print(u)
        return
    x = (v-u)//2
    if x&u == 0:
        print(2)
        print(x|u, x)
    else:
        print(3)
        print(u, x, x)

if __name__ == "__main__":
    main()