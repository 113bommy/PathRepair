def main():
    _ = input()
    numbers = map(int, input().split())

    print(' '.join(map(str, sorted(numbers))))

