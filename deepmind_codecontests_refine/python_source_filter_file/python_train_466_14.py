
m = input().split()
w = input().split()

h= input().split()

max_points = [500, 1000, 1500, 2000, 2500]
scores = 0
for i in range(0, 5):
   scores += max((0.3 * max_points[i]), ((1 - (int(m[i]) / 250)) * max_points[i]) - (50 * int(w[i])))

scores += (int(h[0]) * 100)
scores += (int(h[1]) * 50)

print(int(scores))
