def solve():
    s = input()
    zeros = 0
    ones = 0
    for char in s:
        zeros+= (char=='0')
        ones+= (char=='1')

    #print(zeros,' ',ones)
    ans = 1000000
    left_ones = 0
    left_zeros = 0
    right_zeros = zeros
    right_ones = ones 
    
    if len(s)==1:
        print(0)
        return 0    
    for char in s:
        is_zero = (char=='0')
        if is_zero:
            left_zeros+=1
            right_zeros-=1
        else:
            left_ones+=1
            right_ones-=1

        zero_one_cost = left_ones+right_zeros
        ans = min(ans,zero_one_cost)
        one_zero_cost = left_ones+right_zeros
        ans = min(ans,one_zero_cost)

    print(ans)
        

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
