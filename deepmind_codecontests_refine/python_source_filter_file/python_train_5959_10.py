from functools import partial
height, width, _ = (int(x) for x in input().split(" "))
print(width-1+height-1+width*height-2)
pr = partial(print, sep="", end="", flush=False)
# first stage
for _ in range(width-1):
    pr("L")
for _ in range(height-1):
    pr("U")
for cur_w in range(1, width+1):
    if cur_w % 2 == 1:
        # we are in the top row
        pr("D"*(height-1))
        if cur_w == width:
            break
        pr("R")
    else:
        # we are in the bottom row
        pr("U"*(height-1))
        if cur_w == width:
            break
        pr("R")
print()
