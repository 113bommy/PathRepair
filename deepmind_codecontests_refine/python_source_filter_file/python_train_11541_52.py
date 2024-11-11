import fraction
a, b, c = map(int, input().split())
print("YES" if c%(fraction.gcd(a,b)) == 0 else "NO")