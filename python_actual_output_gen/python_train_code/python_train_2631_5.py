if __name__ == '__main__':
    n = int(input())
    words = input().split(' ')
    roots = set()
    for word in words:
        roots.add("".join(set(word)))
    print(len(roots))
