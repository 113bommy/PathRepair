h1, h2 = map(int, input().split())
k1, k2 = map(int, input().split())
a, b, c, d = map(int, input().split())
H = h1 * a + h2 * b + h1 // 10 * c + h2 // 10 * d
K = k1 * a + k2 * b + k1 // 10 * c + k2 // 10 * d
print('hiroshi' if H>K else 'even' if H==K else 'kenjiro')
