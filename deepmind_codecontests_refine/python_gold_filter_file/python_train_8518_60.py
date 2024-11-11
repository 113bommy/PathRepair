import re


def resolve():
    s = input()
    print("YES" if re.match("A?KIHA?BA?RA?$", s) else "NO")


if __name__ == "__main__":
    resolve()
