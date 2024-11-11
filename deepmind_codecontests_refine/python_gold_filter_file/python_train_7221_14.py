# input consists of 5 lines of 5 inputs
# output the amount of moves needed to make 1 in the middle

for i in range(5):
    s = input().find('1')
    if(~s):
        print(int(abs(i-2) + abs(s/2 - 2)))
