def sol(h, m):
    return 24*60 - h*60 - m

def main():
    t, = [int(x) for x in input().split()]
    for _ in range(t):
        h, m = [int(x) for x in input().split()]
        print(sol(h, m))

main()
