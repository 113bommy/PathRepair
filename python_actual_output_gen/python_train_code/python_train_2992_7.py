n,m,k = map(int,input().split())
army = []
for _ in range(m+1):
    army.append(int(input()))
def solve( A,  B):

    count = 0

    # since, the numbers are less than 2^31
    # run the loop from '0' to '31' only
    for i in range(0,32):

        # right shift both the numbers by 'i' and
        # check if the bit at the 0th position is different
        if ((( A >>  i) & 1) != (( B >>  i) & 1)):
             count=count+1
    return count
ans = 0
for i in range(m+1):
    if solve(army[i],army[-1]) < k:
        ans+=1
print(ans)
