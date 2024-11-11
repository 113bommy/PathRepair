t = int(input())
i = 0
answers = []
while i < t:
    answer = 'Yes'
    n, x = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    a.sort()
    b.sort(reverse = True)
    j = 0
    while j < n:
        if a[j] + b[j] > x:
            answer = 'No'
            break
        j+=1
    answers.append(answer)
    i+=1
    if i < t:
        input()
print(*answers)