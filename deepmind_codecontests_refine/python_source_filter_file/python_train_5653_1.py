import sys
import bisect

def load_sys():
    return sys.stdin.readlines()
 
def load_local():
    with open('input.txt','r') as f:
        input=f.readlines()
    return input

def busy_robot(commands):
    idx_end = cur_pos = target = 0
    events = [x[0] for x in commands]
    positions = [0] + [None]*len(commands)
    ans = 0
    for i in range(len(commands)):
        if i == idx_end:
            positions[i] = cur_pos = target
            target = commands[i][1]
            idx_end = bisect.bisect_left(events, commands[i][0] + abs(cur_pos - target))
            continue
        if cur_pos > target:
            cur_pos += events[i-1] - events[i]
        elif cur_pos < target:
            cur_pos += events[i] - events[i-1]
        positions[i] = cur_pos
    
    positions[-1] = target
    #print(positions)
    for i in range(len(commands)):
        mn = min(positions[i],positions[i+1])
        mx = max(positions[i],positions[i+1])

        if mn <= commands[i][1] <= mx:
            ans += 1
    return ans

#input=load_local()
input=load_sys()
 
TEST_CASES = []
case = [] 
i = 0

while i <= len(input):
    if i == len(input):
        TEST_CASES.append(case)
        break
    input[i] = input[i].split()
    if len(input[i]) == 1 and case:
        TEST_CASES.append(case)
        case = []
    elif len(input[i]) == 2:
        case.append([int(x) for x in input[i]])
    i += 1



for commands in TEST_CASES:
    print(busy_robot(commands))