I = lambda: map(int, input().split(":"))

h, m = I()
ph, pm = I()
h, m = h-ph, m-pm
h, m = (h+m//60)%24, m%60
print(f"{h:02}:{m:02}")