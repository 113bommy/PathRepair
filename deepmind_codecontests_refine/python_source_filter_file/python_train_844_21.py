def main():
    n = int(input())
    s = ['a', 'b', 'c', 'd'] * (n // 2)
    return ''.join(s)[:n]
print(main())

