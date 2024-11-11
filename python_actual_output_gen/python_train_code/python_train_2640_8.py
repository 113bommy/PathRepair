def three_parts_of_an_array() :
    p1 = 0
    p2 = n - 1
    m = -1
    s1 = arr[0]
    s2 = arr[n - 1]
    while p1 < p2 :
        if (s1 == s2) :    
            m = max(m, s1)
            p1 += 1
            s1 += arr[p1]
            p2 -= 1
            s2 += arr[p2]

        elif s1 < s2 :
            p1 += 1
            s1 += arr[p1]
        else :
            p2 -= 1
            s2 += arr[p2]
    return m
    
n = int(input())
arr = list(map(int, input().split()))
print(three_parts_of_an_array())