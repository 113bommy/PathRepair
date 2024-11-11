def main():
    global visited, adj, sets
    print = out.append
    ''' Cook your dish here! '''
    n, m, k = get_list()
    li = get_list()
    li.sort()
    offers = [[10**10, 0]]  # Prevent index out of bound in while loop at line 15
    for _ in range(m):
        offers.append(get_list())
    offers.sort()
    best_y = [0]
    ptr = -1
    for i in range(k):
        best_y.append(best_y[-1])
        while offers[ptr+1][0] <= i+1:
            ptr += 1
            best_y[-1] = max(best_y[-1], offers[ptr][1])
        x, y = 1, i
        while x<=y:
            best_y[-1] = max(best_y[-1], best_y[x]+best_y[y])
            x+=1
            y-=1
    #print(best_y, li)
    dp = [0]
    for i in range(1, k+1):
        prefix_sm = [0]
        dp.append(dp[-1]+li[i-1])
        #print(i, dp)
        for j in range(i-1, 0, -1):
            prefix_sm.append(prefix_sm[-1]+li[j])
            x = i-j
            #print("Prefix sm", prefix_sm, x)
            dp[-1] = min(dp[-1], dp[j]+ prefix_sm[x-best_y[x]])
    print(dp[k])


''' Coded with love at India by Satyam Kumar '''
import sys
#from collections import defaultdict
input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
out = []
get_int = lambda: int(input())
get_list = lambda: list(map(int, input().split()))
main()
# [main() for _ in range(int(input()))]
print(*out, sep='\n')