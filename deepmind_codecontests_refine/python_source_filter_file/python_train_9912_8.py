
tests = int(input())

for te in range(tests):
    n,s = list(map(int,input().split()))
    arr = list(map(int,input().split()))
    pref = [0 for i in range(n)]
    pref[0] = arr[0]
    for i in range(1,n):
        pref[i] = pref[i-1] + arr[i]
    if(pref[n-1] <= s):
        print(0)
        continue
    maxa = -1
    answer = -1
    for i in range(n):
        score = s + arr[i]
        low = 0
        high = n-1
        index = -1
        while(low <= high):
            mid = (low + high)//2
            if(mid >= i and score >= pref[mid]):
                index = mid
                low = mid + 1
            elif(mid < i and s >= pref[i]):
                index = mid
                low = mid + 1
            else:
                high = mid - 1

        if(maxa < index):
            maxa = index
            answer = i
    if(answer == -1):
        print(0)
    else:
        print(answer + 1)
