t = int(input())
answers = []
for i in range(t):
    n,k,d = map(int,input().split())
    lst = list(map(int,input().split()))
    find = []
    for y in range(n-d+1):
        meet = []
        for j in range(y,y+d):
            if lst[j] not in meet:
                meet.append(lst[j])
    find.append(len(meet))
    answers.append(min(find))
for x in answers:
    print(x)