import math
for t in range(int(input())):
    length,good,bad=map(int,input().split())
    good_len=math.ceil(length/2)
    complete_cycle_days=math.floor(good_len/good)*(good+bad)
    no_of_good_more=good_len-(math.floor(good_len/good)*good)
    if no_of_good_more==0:
        complete_cycle_days-=bad
    complete_cycle_days+=no_of_good_more
    print(max(length,complete_cycle_days))