a_total = sum(map(int, input().split()))
b_total = sum(map(int, input().split()))
n = int(input())

def solve(a_total, b_total):
    a_need, a_left = divmod(a_total, 5)
    b_need, b_left = divmod(b_total, 10)
    
    a_left = min(1, a_left)
    b_left = min(1, b_left)
    
    res = a_need + a_left + b_need + b_left
    check = res == n
    
    return "YES" if check else "NO"
    
print(solve(a_total, b_total))