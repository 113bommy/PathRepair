#!/usr/bin/python3

def main():
    a = input() + "".join(reversed(input()))
    b = input() + "".join(reversed(input()))

    a = a[:a.find("X")] + a[a.find("X") + 1:]
    b = b[:b.find("X")] + b[b.find("X") + 1:]

    for i in range(3):
        if a[i:] + a[:i] == b:
            return True
    return False

if main():
    print("YES")
else:
    print("NO")
