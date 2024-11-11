def answer(a,n):
    i,j = n-1,n-1
    ans = n
    while i > 0:
        if i < j:
            j = i
        if a[i] != 0:
            tmp = i - a[i]
            if tmp <= 0:
                ans-=i
                break
            if tmp < j:
                ans-=(j-tmp)
                j = tmp
        i-=1

    return ans




n = int(input())
a = [int(i) for i in input().split()]

print(answer(a,n))