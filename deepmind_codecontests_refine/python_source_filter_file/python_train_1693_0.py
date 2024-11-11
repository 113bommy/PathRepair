def prefix_flip(index , arr):
    s = []
    for i in range(index-1 , -1 , -1):
        s.append(str((int(arr[i])^1)))
    s.append(arr[index:])
    return s

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(input())
    b = list(input())
    answer = []
    for i in range(n-1 , -1 , -1):
        if b[i] == a[i]:
            continue
        elif b[i] == a[0]:
            answer.append(1)
            answer.append(i+1)
            a[0] = str(int(a[0])^1)
            a = prefix_flip(i , a)
        else:
            answer.append(i+1)
            a = prefix_flip(i , a)
    print(len(answer) , *answer)