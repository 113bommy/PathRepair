import math
n, red, blue, red_cost, blue_cost = map(int, input().split())
reds = n//red - n//((red*blue)//math.gcd(red,blue))
blues = n//blue - n//((red*blue)//math.gcd(red,blue))
ans = reds*red_cost + blues*blue_cost + max(blue_cost, red_cost)*(n//((red*blue)//math.gcd(red,blue)))
print(int(ans))   
