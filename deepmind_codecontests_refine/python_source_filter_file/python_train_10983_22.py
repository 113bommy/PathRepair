
def main():
    s = input()

    lower = len([c for c in s if c.islower()])
    upper = len(s) - lower

    if upper > lower:
        print(s.lower())
    else:
        print(s.upper())

if __name__ == "__main__":
    main()