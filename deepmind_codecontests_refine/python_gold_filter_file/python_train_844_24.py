def main():
    n = int(input())
    s = ['a', 'b', 'c', 'd'] * n
    return ''.join(s)[:n]
print(main())

