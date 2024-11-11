#Problem A

def solve(n, s):
    if s <= n: return 1
    elif s % n == 0: return s/n
    return(1 + s // n)

def main():
    inl = input().strip().split()
    n, s = int(inl[0]), int(inl[1])
    print(solve(n,s))

if __name__ == '__main__':
    main()
