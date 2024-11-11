def question3():
    N,ohh,wooh = map(int,input().split())
    arr = [1]
    if N == 1:
        return [1,[1]]
    remians = N - ohh - wooh
    if wooh == 0 and ohh >= N - 1:
        return [-1,[]]
    sum1 = 1 
    if wooh == 0:
        arr.append(1)
    for i in range(wooh):
        arr.append(sum1+1)
        sum1 += arr[-1] 
    for i in range(ohh):
        arr.append(arr[-1]+1)
    for i in range(remians-1):
        arr.append(arr[-1])
    if wooh == 0:
        arr.pop()
    print("length",len(arr))
    if arr[-1] > 50000:
        return [-1,[]]
    return [1,arr]    

        
remained_test_cases = 1 
while remained_test_cases > 0:
    ans = question3()
    if ans[0] == -1 :
        print(-1)
    else:
        print(*ans[1])
    remained_test_cases -= 1 