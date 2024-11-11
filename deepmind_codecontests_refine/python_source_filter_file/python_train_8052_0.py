# def hidden_nums():
#     left, right = map(int, input().split())
#     seen = set([left, right, 7-left, 7-right])
#     hidden = [i for i in range(1, 7) if i not in seen]
#     return hidden

# def solve():
#     n, top = int(input()), int(input())
#     bottom = [7-top]
#     count = 0
#     for i in range(n-1):
#         hidden = hidden_nums()
#         for b in bottom: 
#             if b in hidden: hidden.remove(7-b)
#         bottom = hidden
#         if len(bottom) == 2:
#             count+=1
#     if top in hidden_nums() and count == 0:
#         return 'YES'
#     return 'NO'
# print(solve())



def hidden_nums():
    left, right = map(int, input().split())
    seen = set([left, right, 7-left, 7-right])
    hidden = [i for i in range(1, 7) if i not in seen]
    return hidden

def solve():
    n, top = int(input()), int(input())
    bottom = [7-top]
    count = 0
    for i in range(n-1):
        hidden = hidden_nums()
        if top not in hidden and bottom not in hidden:
            return 'NO'
    #     for b in bottom: 
    #         if b in hidden: hidden.remove(7-b)
    #     bottom = hidden
    #     if len(bottom) == 2:
    #         count+=1
    # if top in hidden_nums() and count == 0:
    #     return 'YES'
    return 'YES'
print(solve())