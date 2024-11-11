# problem/1136/B

n,k = [int(n) for n in input().split(" ")]

# stones = [1 for i in range(n)]

# # if closer to left, go left first
# # print(k < n/2)
# if k < (n-1)/2:
#     moves = 0
#     # if k == 0 then we can't go left
#     if k != 0:
#         # go left
#         for i in range(k,-1,-1):
#             if stones[i] > 0:
#                 st = stones[i]
#                 stones[i] -= st
#                 stones[i+1] += st
#                 moves += st

#             # pick up coin
#             moves += 1

#             if i != 0:
#                 # move to the left
#                 moves += 1

#         # we're now at index 0
#         # move k moves back to where we started
#         moves += k + 1
#         k_ = k + 1
#     else:
#         k_ = k

#     # go right
#     for i in range(k_,n):
#         if stones[i] > 0:
#             st = stones[i]
#             stones[i] -= st
#             stones[(i-1)%n] += st
#             moves += st

#         # pick up coin
#         moves += 1

#         if i != n-1:
#             # move to the right
#             moves += 1

# # if closer to right, go right first
# else:
#     moves = 0

#     # if k == n then we can only go left
#     if k != n-1:
#         # go right
#         for i in range(k,n):
#             if stones[i] > 0:
#                 st = stones[i]
#                 stones[i] -= st
#                 stones[i-1] += st
#                 moves += st

#             # pick up coin
#             moves += 1

#             if i != n-1:
#                 # move to the right
#                 moves += 1

        
#         # we're now at index n
#         # move k moves back to where we started - 1
#         moves += (n-k) + 1
#         k_ = k - 1
#     else:
#         k_ = k

#     # go left
#     for i in range(k_,-1,-1):
#         if stones[i] > 0:
#             st = stones[i]
#             stones[i] -= st
#             stones[(i+1)%n] += st
#             moves += st

#         # pick up coin
#         moves += 1

#         if i != 0:
#             # move to the left
#             moves += 1

# print(moves)

# print(k < (n-1)/2)

if k == 1:
    # pickup n+1 stones, move n-1 times and pickup n gold coins
    print(3*n)

elif k == n:
    # pickup n+1 stones, move n-1 times and pickup n gold coins
    print(3*n)

# go left
elif k <= int(n/2):
    steps = 0
    # pickup k stones, move k-1 times and pickup k gold coins 
    steps += 3*k - 1
    # move k steps
    steps += k
    # pickup (n-k)+1 stones, move (n-k)-1 times and pickup (n-k) gold coins
    steps += (n-k)*3
    print(steps)

# go right
else:
    steps = 0
    # pickup (n-k+1) stones, move (n-k+1)-1 times and pickup (n-k+1) gold coins
    steps += (n-k+1)*3 - 1
    # move (n-k+1) steps
    steps += (n-k+1)
    # pickup (k-1)+1 stones, move (k-1)-1 times and pickup (k-1) gold coins 
    steps += 3*(k-1)
    print(steps)
    
    