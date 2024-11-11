x, y, z = map(int, input().split(" "))

wakaru = x-y

min_ = wakaru - z
max_ = wakaru + z



if (min_ < 0 and max_ >= 0 ) or (min_ <= 0 and max_ > 0):
    out = "?"
elif min_ == 0 and max_ == 0:
    out = "0"
elif min_ < 0 and max_ < 0:
    out = "-"
else:
    out = "+"

print(out)