
def answer3(n, a):
    INF = 10**10
    dp = [1, INF, INF] # represents min days of rest given previous choice was [rest, contest, sport]
    if a[0] == 0:
        dp[0] = 1
    elif a[0] == 1:
        dp[1] = 0
    elif a[0] == 2:
        dp[2] = 0
    else: #a[0] == 3:
        dp[1] = 1
        dp[2] = 1
    #print('dp=', dp)
    
    for day in range(1, n):
        new_dp = [INF, INF, INF]
        for i in range(3): #each of 0, 1, or 2 [rest, contest, sport] chosen on previous day.
            for j in range(3): #each of 0, 1, or 2 [rest, contest, sport] chosen on current day.
                if (i == j) and (i != 0): #can't do same activity twice, but can rest twice.
                    pass
                elif a[day] == 1 and j == 2: #cant do sport today
                    pass
                elif a[day] == 2 and j == 1: #can't do contest today
                    pass
                elif a[day] == 0: #forced day of rest.
                    new_dp = [min(dp) + 1, INF, INF]
                    break #yes, I know this will be run 3 times, but whatever.
                else: #all other options available
                    if j == 0:
                        new_dp[j] = min(new_dp[j], dp[i] + 1)
                    else:
                        new_dp[j] = min(new_dp[j], dp[i] + 0)
        
        dp = new_dp
        #print('dp=', dp)
    return min(dp)




def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    print(answer3(n, a))

    return
main()