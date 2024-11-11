def main():
    n = int(input().strip())
    it = iter(enumerate(input().strip() for _ in range(n)))
    _, s = next(it)
    x, o = s[0], s[1]
    if s[-1] != x or any(_ != o for _ in s[1:-1]):
        return False
    for i, s in it:
        mask = (i, n - i - 1)
        if any(c != (o, x)[j in mask] for j, c in enumerate(s)):
            return False
    return True


print(('NO', 'YES')[main()])