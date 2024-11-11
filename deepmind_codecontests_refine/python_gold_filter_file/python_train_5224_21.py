current = [0 for _ in range(10)]
num_events = input()
events = input()

for i in range(int(num_events)):
    if events[i] == 'L':
        for j in range(len(current)):
            if current[j] == 0:
                current[j] = 1
                break
    elif events[i] == 'R':
        for j in reversed(range(len(current))):
            if current[j] == 0:
                current[j] = 1
                break
    else:
        current[int(events[i])] = 0

def convert(list):
    res = "".join(map(str, list))
    return res

print(convert(current))
