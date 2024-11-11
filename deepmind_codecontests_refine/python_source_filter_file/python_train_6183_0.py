l, d, v, g, r = map(int, input().split())
modulus = g+r
time_to_light = d/v
t = time_to_light
arrival = time_to_light % modulus
if arrival > g:
    t += r+g-arrival
t += (l-d)/v
print(t)
