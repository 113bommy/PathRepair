## C


def check(s: str) -> bool:
    chars = [ord(c) - ord("A") for c in s]
    print(chars)
    for a, b, c in zip(chars, chars[1:], chars[2:]):
        if (a + b) % 26 != c:
            return False
    return True


s = input().strip()
print("YES" if check(s) else "NO")