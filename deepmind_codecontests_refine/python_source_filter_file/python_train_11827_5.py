from operator import itemgetter
n, money = list(map(int, input().split()))

costs = list(map(int, input().split()))
# def check(i, total, indices, taken, left):
#
#     # if i in arr:
#     #     print(i, arr)
#     #     return arr[i]
#     if i > len(costs)-1 and taken != 0:
#
#         return ((left)-total-indices*taken, taken)
#     elif i < len(costs):
#
#         if (total+costs[i]) + (indices+i+1)*(taken+1) <= left:
#
#             boo = max(check(i+1, total+costs[i], indices+i+1,taken+1, left), check(i+1, total, indices, taken, left), key=itemgetter(1,0))
#             return boo
#         else:
#             return ((left)-total-indices*taken, taken)
#     return (0,0)
#
# a = list(check(0,0,0,0,money)[::-1])
# a[1] = money-a[1]
# print(*a)
#

def binary_search():
    cost = 0
    ans = 0
    u = len(costs)+1
    d = 0
    while u-1 >= d:
        mid = (u+d)//2
        k = price(mid, n)
        if k > money:
            u = mid-1
        elif k < money:
            d = mid +1
            cost = k
            ans = mid
        else:
            print(mid, money)
            return
    print(ans, cost)
def price(k, n):
    b = []
    for i in range(1,n+1):
         b.append(costs[i-1]+i*k)
    b.sort()    
    return sum(b[:k])

binary_search()