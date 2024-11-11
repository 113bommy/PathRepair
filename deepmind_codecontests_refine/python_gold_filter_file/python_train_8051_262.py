def solve(n, percents):
    return sum(percents) / (n)
    
n = int(input())
percents = map(int, input().split())
print(solve(n, percents))