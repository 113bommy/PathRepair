k=input()
s=input()
side=0
height=0
k=0
for letter in s:
    if letter=='R':
        if side == 0:
            side =1
        elif side == 1:
            side=1
        else:
            k+=1
            side=1
            height=0
    if letter=='L':
        if side == 0:
            side =-1
        elif side == -1:
            side=-1
        else:
            k+=1
            side=-1
            height=0
    if letter=='U':
        if height == 0:
            height =1
        elif height == 1:
            height=1
        else:
            k+=1
            height=1
            size=0
    if letter=='D':
        if height == 0:
            height =-1
        elif height == -1:
            height=-1
        else:
            k+=1
            height=-1
            size=0
print(k+1)