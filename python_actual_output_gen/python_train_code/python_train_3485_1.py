
for _ in range(int(input())):
    N = int(input())
    Count = [0] * 26
    for i in range(N):
        temp = input()
        for x in temp:
            Count[ord(x) - ord("a")] += 1
    flag = 0
    for i in range(26):
        if(Count[i]%N!=0):
            print("YES")
            flag = 1
            break
    if(not flag):
        print("NO")
