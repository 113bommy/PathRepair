def gcd(a, b):
    if a == 0:
        return b
    else:
        return gcd(b % a, a)

max_w, max_h, w, h = map(int, input().split())
g = gcd(w, h)
w /= g
h /= g

ans = min(max_w // w, max_h // h)

print(ans)
