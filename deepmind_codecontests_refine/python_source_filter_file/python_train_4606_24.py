def helper_to_binary(n):
    ans = []
    for i in range(6):
        ans.append(n%2)
        n = n//2
    return ans[::-1]
def helper_from_binary(l):
    ans = 0
    for i in range(6):
        ans += l[::-1][i]*2**i
    return ans
n = int(input())
permute = [0,5,3,2,4,1]
print(helper_from_binary([helper_to_binary(5)[permute[i]] for i in range(6)]))