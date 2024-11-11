t = int(input())
count = 0

if(t>=5):
    n = t // 5
    t = t % 5
    count = count+n
if(t>=4):
    n = t // 4
    t = t % 4
    count = count+n
if(t>=3):
    n = t // 3
    t = t % 3
    count = count+n
if(t>=2):
    n = t // 2
    t = t % 2
    count = count+n
if(t>=1):
    n = t // 1
    t = t % 1
    count = count+n

print(count)