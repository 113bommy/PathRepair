s = input()


def caps_lock(s: str) -> bool:
    """Returns true if s has been typed with caps lock accidentally on"""
    all_upper = all(c.isupper() for c in s)
    all_upper_but_first = s[0].islower() and all(c.isupper() for c in s[1:])
    return all_upper or all_upper_but_first


if caps_lock(s):
    ans = ''
    for c in s:
        if c.isupper():
            ans += c.lower()
        else:
            ans += c.upper()
else:
    ans = s

print(s)
