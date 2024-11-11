string = ''
output = [0] * 10

no_events = input()
events = input()

for i in range(int(no_events)):
    if events[i] == 'L':
        for j in range(10):
            if output[j] == 0:
                output[j] = 1
                break
    elif events[i] == 'R':
        for j in range(9,-1,-1):
            if output[j] == 0:
                output[j] = 1
                break
    else:
        output[int(events[i])] = 0

for i in output:
    string += str(i)
print(string)