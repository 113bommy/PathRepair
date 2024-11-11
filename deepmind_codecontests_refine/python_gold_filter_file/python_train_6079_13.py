
def answer(s, m, l, r): #l and r are arrays m units long. m may be > or < len(s)
    # needs to be solved in O(n+q) rather than O(n*q).
    ans = []
    ans.append(0) #since they have 1-based arrays.
    count = 0
    for i in range(len(s)-1):
        if s[i+1] == s[i]:
            count += 1
        ans.append(count)
    #ans array should be running sum.
    #print('ans=', ans)
    for i in range(m):
        print(ans[r[i]-1] - ans[l[i]-1])

    return #Null

def main():
    s = input()
    m = int(input())
    l = [0] * m
    r = [0] * m
    for j in range(m):
        l[j], r[j] = [int(i) for i in input().split()]
    
    answer(s, m, l, r)

main()