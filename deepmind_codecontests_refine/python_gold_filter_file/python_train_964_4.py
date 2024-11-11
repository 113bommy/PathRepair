for x in range(int(input())):
    n, k = map(int, input().split())
    string = list(input())
    lose = []
    count = 0
    score, first, last = 0, 0, 0
    for i in range(n-1):
        if string[i] == string[i+1]:
            count += 1 
            if i == n-2:
                if string[i] == 'L':
                    lose.append(count+1)
                if string[i] == 'W':
                    score = score+(count)*2+1 
                break
        else:
            if string[i] == 'W':
                score = score+(count)*2+1
                count = 0
                if i == n-2:
                    lose.append(1)
            else:
                lose.append(count+1)
                count = 0
                if i == n-2:
                    score += 1
    if n == 1:
        if string[0] == 'W':
            score = 1 
        else:
            last = 1
    else:
        if string[-1] == 'L' and lose:
            last = lose.pop()
        if string[0] == 'L' and lose:
            first = lose.pop(0)
    lose = sorted(lose)
    for i in lose:
        if k-i < 0:
            score = score+(k*2)
            k = 0
            break
        else:
            k -= i
            score = score+(i*2)+1
    if k >= last and score > 0:
        score = score+(last*2)
        k -= last
    elif last > k and score > 0:
        score = score+(k*2)
        k = 0
    elif last > 0 and k >= last:
        score = score+last*2-1
        k -= last
    elif k > 0 and last > k:
        score = score+k*2-1
        k = 0
    if k >= first and score > 0:
        score = score+(first*2)
        k -= first
    elif first > k and score > 0:
        score = score+(k*2)
        k = 0
    print(score)


