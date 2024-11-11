def is_possible(num_days):
    if num_days % len(string) == 0:
        diff_wind = ((num_days // len(string)) * pref[-1][0],(num_days // len(string)) * pref[-1][1])
    else:
        diff_wind = ((num_days // len(string)) * pref[-1][0] + pref[num_days % len(string) - 1][0],(num_days // len(string)) * pref[-1][1] + pref[num_days % len(string) - 1][1])
    diff_ship = ((diff[0] - diff_wind[0],diff[1] - diff_wind[1]))
    #print(diff_ship)
    return abs(diff_ship[0]) + abs(diff_ship[1]) <= num_days
x,y = [int(s) for s in input().split()]
x1,y1 = [int(s) for s in input().split()]
diff = ((x1 - x,y1 - y))
amount = int(input())
string = input()
motions = []
pref = [] 
for i in range(len(string)):
    if string[i] == 'U':
        motions.append((0,1))
    if string[i] == 'D':
        motions.append((0, -1))
    if string[i] == 'R':
        motions.append((1,0))
    if string[i] == 'L':
        motions.append((-1,0))
#print(motions)
pref.append(motions[0])
#print(pref)
for i in range(1, len(motions)):
    pref.append((motions[i][0] + pref[-1][0],motions[i][1] + pref[-1][1]))
#print(pref)
left = -1
right = int(10e18)
#print(is_possible(6))
while right - left > 1:
    middle = (right + left) // 2
    if is_possible(middle):
        right = middle
    else:
        left = middle
if right != int(10e18):
    print(right)
else:
    print(-1)