m = list(map(int, input().split()))
w = list(map(int, input().split()))
h1,h2 = map(int, input().split())
points = 500
output = 0

for i in range(5):
    output += max(0.3*points, (1 - m[i] / 250) * points - 50 * w[i])
    points += 500
if h1 > 0:
    output += h1 * 100
if h2 > 0:
    output -= h1 * 50
print(int(output))