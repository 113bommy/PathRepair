from string import ascii_letters

def solve(s):
    s = s.lower()
    cons = set(ascii_letters) - set(list("aeiou"))
    for i in reversed(s):
        if i in "aeiou":
            return "YES"
        elif i in cons:
            return "NO"


def main():
    s = input()
    print(solve(s))


main()
