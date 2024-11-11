n = int(input())
direction = input()
array = list(map(int, input().split()))

count = direction.count('RL')

if count == 0:
    print(-1)
    exit(0)
else:
    first = direction.index('RL')
    dist = array[first + 1] - array[first]
    while count > 1:
        first = direction[first + 1:].index('RL')
        if array[first + 1] - array[first] < dist:
            dist = array[first + 1] - array[first]
        count -= 1
    print(dist // 2)



