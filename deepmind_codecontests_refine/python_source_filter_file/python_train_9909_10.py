n = int(input())
d = int(input())
e = int(input())

min_d = d
min_e = 5*e

tempd = n%min_d
tempe = n%min_e



max_d = int(n/d)
max_e = int(n/e)
min_r = min(tempd, tempe)

for i in range(max_d):
    if ((n-(i*min_d))%min_e < min_r):
        min_r = (n-(i*min_d))%min_e

for i in range(max_e):
    if ((n - (i*min_e))%min_d < min_r):
        min_r = (n - (i*min_e))%min_d
        
print(min_r)