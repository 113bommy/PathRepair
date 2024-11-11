s = input()
state = 0

for c in s:
    diff = ord(c) - state
    state = ord(c)
    if diff < -1:
        diff += 256
    for _ in range((diff+1)//2):
        print('....\n.XX.\nXXXX')
    if ord(c)%2==1:
        print('....\nX...\nX...')
    else:
        print('X...')