# print("Input number of test cases")
t = int(input())
for i in range(t):
    # print("Input n")
    n = int(input())
    print("Input the n integers")
    a = [int(x) for x in input().split()]

    answer = 0
    smallestsofar = a[-1]
    for i in range(len(a)-2, -1, -1):
        if a[i] > smallestsofar:
            answer += 1
        elif a[i] < smallestsofar:
            smallestsofar = a[i]
    print(answer)
        
