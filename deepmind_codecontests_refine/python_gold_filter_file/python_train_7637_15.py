n = int(input())
curr = 0
time = 0
prev = 0
for i in range(n):
    h = int(input())
    if prev<=h:
        curr = prev
    else:
        time+=(prev-h)
        curr = h
    time+= (h-curr)+1
    prev = h

print(time+(n-1))# for jumps