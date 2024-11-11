n, k = [int(i) for i in input().split()]
 
screen = []
 
messages = [int(i) for i in input().split() ]
 
 
for ID in messages:
 
    if ID not in screen: # message not on screen 
 
        screen.insert(0,ID)
 
print(k if len(screen) > k else len(screen))
print(' '.join([str(i) for i in screen[0:k]]))