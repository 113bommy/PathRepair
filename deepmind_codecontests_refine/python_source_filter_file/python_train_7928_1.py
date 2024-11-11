def check(dp,req,mid):
    curr = dp[mid]
    for i in range(26):
        if curr[i] < req[i]:
            return False

    return True

def solve(dp,t):
    n = len(dp)
    l = 0
    r = n
    req = [0]*26
    for i in t:
        req[ord(i)-97] += 1

    while l < r:
        mid = (l+r)//2
        if check(dp,req,mid):
            #print('here',l,r,mid,t)
            r = mid-1
        else:
            l = mid+1

    print(r+2)

def main():
    n = int(input())
    s = input()
    dp = [[0 for i in range(26)] for j in range(n)]
    dp[0][ord(s[0])-97] += 1
    for i in range(1,n):
        for j in range(26):
            dp[i][j] = dp[i-1][j]

        dp[i][ord(s[i])-97] += 1
        
    m = int(input())
    for i in range(m):
        t = input()
        solve(dp,t)


main()
