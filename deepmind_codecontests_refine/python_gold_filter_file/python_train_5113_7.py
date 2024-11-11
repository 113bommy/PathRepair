arr = list(map(int, input().strip().split()))
numOfStat = arr[0] - 1
position = arr[1] - 1
line1 = list(map(int, input().strip().split()))
line2 = list(map(int, input().strip().split()))
var = 0
if line1[0] is 1 and line1[position] is 1:
    answer = "YES"
    print(answer)
else:
    if line1[0] is 0:
        answer = "NO"
        print(answer)
    else:
        if line2[position] is 1:
            accept = 0
            for i in range(arr[1], arr[0], 1):
                var = line1[i] + line2[i]
                if var == 2:
                    accept += 1
                i += 1
            if accept == 0:
                answer = "NO"
                print(answer)
            else:
                answer = "YES"
                print(answer)
        else:
            answer = "NO"
            print(answer)