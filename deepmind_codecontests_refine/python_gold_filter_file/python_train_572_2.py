# Description of the problem can be found at http://codeforces.com/problemset/problem/633/A

a, b, c = map(int, input().split())

for i in range(c // a + (2 if c % a == 0 else 1)):
    for j in range((c - i * a) // b + (2 if (c - i * a) % b == 0 else 1)):
        if (c - i * a - j * b) == 0:
            print("Yes")
            quit()

print("No")