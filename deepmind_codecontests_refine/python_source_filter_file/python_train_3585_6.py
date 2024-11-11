n = int(input())
position = input()

n_X = int(position.count('X'))
t= 0

if n_X < (n//2):
    ele = n//2 - n_X
    x = 0
    for i in range(n):
        if position[i] == 'x' and x <= ele :
            x += 1
            t += i + 1
            position = position[:i] + 'X' + position[i+1:]
            if x == ele :
                break
elif n_X > (n//2) :
    ele = n_X - n//2
    x = 0
    for i in range(n):
        if position[i] == 'X' and x <= ele :
            x += 1
            t += i + 1
            position = position[:i] + 'x' + position[i+1:]
            if x==ele :
                break

print(t)
print(position)
